// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DectusCharacter.h"
#include "InputActionValue.h"
#include "DectusPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DECTUS_API ADectusPlayerCharacter : public ADectusCharacter
{
	GENERATED_BODY()
	
public: 
	ADectusPlayerCharacter();

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

protected:
	// To add mapping context
	virtual void BeginPlay();
};
