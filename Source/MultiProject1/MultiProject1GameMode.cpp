// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MultiProject1GameMode.h"
#include "MultiProject1Character.h"
#include "UObject/ConstructorHelpers.h"

AMultiProject1GameMode::AMultiProject1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
