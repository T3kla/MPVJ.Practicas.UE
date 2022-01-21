#include "MyDoor.h"

AMyDoor::AMyDoor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComponent);

	Frame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
	Frame->SetupAttachment(RootSceneComponent);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(RootSceneComponent);
}

void AMyDoor::BeginPlay()
{
	Super::BeginPlay();
}

void AMyDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

