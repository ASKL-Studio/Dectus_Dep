// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DectusCharacter.h"
#include "InputActionValue.h"
#include "../Interfaces/WallRunnableCharacter.h"
#include "DectusPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DECTUS_API ADectusPlayerCharacter : public ADectusCharacter, public IWallRunnableCharacter
{
	GENERATED_BODY()
	
public: 
	ADectusPlayerCharacter(const class FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

public:
	/** Wall run interface functions */
	bool IsTheWallRunnable(FVector WallNormal) override;
	void BeginWallRun(FVector WallNormal) override;
	void EndWallRun() override;

protected:
	virtual void BeginPlay() override;
	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode = 0) override;
};
