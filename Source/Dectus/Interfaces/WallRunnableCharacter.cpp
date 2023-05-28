// Fill out your copyright notice in the Description page of Project Settings.


#include "WallRunnableCharacter.h"

// Add default functionality here for any IWallRunnableCharacter functions that are not pure virtual.
bool IWallRunnableCharacter::IsTheWallRunnable(FVector WallNormal)
{
	return true;
}

void IWallRunnableCharacter::BeginWallRun(FVector WallNormal)
{

}

void IWallRunnableCharacter::EndWallRun()
{

}
