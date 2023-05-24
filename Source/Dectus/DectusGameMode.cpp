// Copyright Epic Games, Inc. All Rights Reserved.

#include "DectusGameMode.h"
#include "DectusCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADectusGameMode::ADectusGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
