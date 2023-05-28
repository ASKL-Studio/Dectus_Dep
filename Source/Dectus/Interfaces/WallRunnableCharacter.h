// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WallRunnableCharacter.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType, NotBlueprintable)
class UWallRunnableCharacter : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DECTUS_API IWallRunnableCharacter
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable)
	virtual bool IsTheWallRunnable(FVector WallNormal);

	UFUNCTION(BlueprintCallable)
	virtual void BeginWallRun(FVector WallNormal);

	UFUNCTION(BlueprintCallable)
	virtual void EndWallRun();
};
