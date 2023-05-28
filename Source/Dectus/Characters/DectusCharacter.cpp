// Copyright Epic Games, Inc. All Rights Reserved.

#include "DectusCharacter.h"
#include <AbilitySystemComponent.h>
#include "GameFramework/CharacterMovementComponent.h"
#include <Abilities/GameplayAbility.h>
#include "../GameplayAbility/DectusAttributeSet.h"
#include "../Components/DectusCharacterMovementComponent.h"

ADectusCharacter::ADectusCharacter(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.SetDefaultSubobjectClass<UDectusCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	Attributes = CreateDefaultSubobject<UDectusAttributeSet>("Attributes");

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

	InitializeAttributes();
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

void ADectusCharacter::InitializeAttributes()
{
	if (AbilitySystemComponent && DefaultAttribute)
	{
		FGameplayEffectContextHandle Context = AbilitySystemComponent->MakeEffectContext();
		Context.AddSourceObject(this);

		FGameplayEffectSpecHandle Handle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttribute, 1, Context);

		if (Handle.IsValid())
		{
			FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*Handle.Data.Get());
		}
	}
}