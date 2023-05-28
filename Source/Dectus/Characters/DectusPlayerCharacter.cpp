// Fill out your copyright notice in the Description page of Project Settings.


#include "DectusPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "../Components/DectusCharacterMovementComponent.h"


//////////////////////////////////////////////////////////////////////////
// ADectusPlayerCharacter

ADectusPlayerCharacter::ADectusPlayerCharacter(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.SetDefaultSubobjectClass<UDectusCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

bool ADectusPlayerCharacter::IsTheWallRunnable(FVector WallNormal)
{
	bool bIsTheWallRunnable    = false;
	bool bWallSteepCheck       = false;
	bool bCharacterVectorCheck = false;
	bool bCharacterSpeedCheck  = false;

	float Z = WallNormal.Z;
	float CosTheta = WallNormal.CosineAngle2D(GetActorForwardVector());
	float Theta = acos(CosTheta) * 180 / PI;
	float Speed = GetVelocity().Length();

	if (Z >= -0.52 && Z <= 0.52)
	{
		bWallSteepCheck = true;
	}
	if (Theta >= 30 && Theta <= 80)
	{
		bCharacterVectorCheck = true;
	}
	if (Speed >= 2000)
	{
		bCharacterSpeedCheck = true;
	}
	if (bWallSteepCheck && bCharacterVectorCheck && bCharacterSpeedCheck)
	{
		bIsTheWallRunnable = true;
	}

	return bIsTheWallRunnable;
}

void ADectusPlayerCharacter::BeginWallRun(FVector WallNormal)
{
	GetCharacterMovement()->SetPlaneConstraintEnabled(true);
	GetCharacterMovement()->SetPlaneConstraintNormal(WallNormal);
	GetCharacterMovement()->SetMovementMode(MOVE_Custom, 1);
}

void ADectusPlayerCharacter::EndWallRun()
{
	GetCharacterMovement()->SetPlaneConstraintEnabled(false);
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector());
}

void ADectusPlayerCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ADectusPlayerCharacter::OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode /*= 0*/)
{
	// If the last movement mode is wall run 
	if (PrevMovementMode == MOVE_Custom && PreviousCustomMode == 1)
	{
		EndWallRun();
	}
}