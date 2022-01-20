#include "MyKey.h"

AMyKey::AMyKey()
{
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComponent);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootSceneComponent);
}

void AMyKey::BeginPlay()
{
	Super::BeginPlay();
}

void AMyKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

