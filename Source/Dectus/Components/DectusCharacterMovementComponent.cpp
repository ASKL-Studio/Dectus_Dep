// Fill out your copyright notice in the Description page of Project Settings.


#include "DectusCharacterMovementComponent.h"

void UDectusCharacterMovementComponent::PhysCustom(float deltaTime, int32 Iteration)
{
	Super::PhysCustom(deltaTime, Iteration);

	switch (CustomMovementMode)
	{
		case 1 :
			PhysWallRunning(deltaTime, Iteration);
			break;
		case 2 : 
			PhysSliding(deltaTime, Iteration);
			break;
		default : 
			break;
	}
}

void UDectusCharacterMovementComponent::PhysWallRunning(float deltaTime, int32 Iteration)
{

}

void UDectusCharacterMovementComponent::PhysSliding(float deltaTime, int32 Iteration)
{

}
