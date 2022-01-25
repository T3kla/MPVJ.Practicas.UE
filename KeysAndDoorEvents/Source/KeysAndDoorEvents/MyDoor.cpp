#include "MyDoor.h"

AMyDoor::AMyDoor()
{
    PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    SetRootComponent(Root);
}

void AMyDoor::BeginPlay()
{
    Super::BeginPlay();
    IsOpen = false;
}

void AMyDoor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyDoor::ToggleOpen()
{
    IsOpen = !IsOpen;

    StateChange(IsOpen);
}
