// Fill out your copyright notice in the Description page of Project Settings.


#include "DectusCustomDebugTools.h"

static TAutoConsoleVariable<int> CVarCharacterMovementDebug(
	TEXT("CharacterMovement.Debug"),
	0, // 0 => disable the debug tool, 1 => velocity, 2=> acceleration
	TEXT("Print variables on character movement component"),
	ECVF_Default
);