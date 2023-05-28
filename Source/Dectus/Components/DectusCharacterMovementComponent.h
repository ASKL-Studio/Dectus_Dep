// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DectusCharacterMovementComponent.generated.h"

/**
 * If the CustomMovementMode is :
 * 1 => Wall Running
 * 2 => Sliding
 */
UCLASS()
class DECTUS_API UDectusCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public : 
	virtual void PhysCustom(float deltaTime, int32 Iteration) override;

	UFUNCTION()
	void PhysWallRunning(float deltaTime, int32 Iteration);

	UFUNCTION()
	void PhysSliding(float deltaTime, int32 Iteration);
};
