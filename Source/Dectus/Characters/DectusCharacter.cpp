// Copyright Epic Games, Inc. All Rights Reserved.

#include "DectusCharacter.h"
#include <AbilitySystemComponent.h>
#include "GameFramework/CharacterMovementComponent.h"
#include <Abilities/GameplayAbility.h>

ADectusCharacter::ADectusCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

UAbilitySystemComponent* ADectusCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ADectusCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	GrantAbilities();
}

void ADectusCharacter::GrantAbilities()
{
	if (AbilitySystemComponent)
	{
		for (TSubclassOf<UGameplayAbility> ability : DefaultAbilities)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(ability, ability->GetDefaultObject<UGameplayAbility>()->GetAbilityLevel(), -1, this));
		}
	}
}
