// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include <AbilitySystemComponent.h>
#include "DectusAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class DECTUS_API UDectusAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData GaleGreavesFuel;
	ATTRIBUTE_ACCESSORS(UDectusAttributeSet, GaleGreavesFuel);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData GaleBurstMagnitude;
	ATTRIBUTE_ACCESSORS(UDectusAttributeSet, GaleBurstMagnitude);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData GaleBurstDuration;
	ATTRIBUTE_ACCESSORS(UDectusAttributeSet, GaleBurstDuration);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData VelSaberCharge;
	ATTRIBUTE_ACCESSORS(UDectusAttributeSet, VelSaberCharge);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData MaxVelSaberCharge;
	ATTRIBUTE_ACCESSORS(UDectusAttributeSet, MaxVelSaberCharge);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UDectusAttributeSet, Health);
};
