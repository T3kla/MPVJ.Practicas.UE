#include "MyDoor.h"

AMyDoor::AMyDoor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyDoor::BeginPlay()
{
	Super::BeginPlay();
}

void AMyDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

