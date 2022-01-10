// Copyright Epic Games, Inc. All Rights Reserved.

#include "PizzaGameMode.h"
#include "PizzaCharacter.h"
#include "UObject/ConstructorHelpers.h"

APizzaGameMode::APizzaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
