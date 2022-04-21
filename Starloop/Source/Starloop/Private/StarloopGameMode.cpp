// Copyright Epic Games, Inc. All Rights Reserved.

#include "StarloopGameMode.h"
#include "StarloopCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStarloopGameMode::AStarloopGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
