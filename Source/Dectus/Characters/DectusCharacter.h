// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <AbilitySystemInterface.h>
#include "DectusCharacter.generated.h"

UCLASS(config=Game)
class DECTUS_API ADectusCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ADectusCharacter();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override; 
	virtual void BeginPlay() override;

	UFUNCTION()
	void GrantAbilities();

	UFUNCTION()
	void InitializeAttributes();

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GameplayAbilities")
	TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GameplayAbilities")
	TSubclassOf<class UGameplayEffect> DefaultAttribute;

	UPROPERTY(BlueprintReadOnly)
	class UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly)
	class UDectusAttributeSet* Attributes;
};

