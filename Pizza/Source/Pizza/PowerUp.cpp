#include "PowerUp.h"

APowerUp::APowerUp()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));

	SphereTrigger->SetSphereRadius(20);

	SetRootComponent(DefaultRoot);
	SphereTrigger->SetupAttachment(DefaultRoot);
}

void APowerUp::BeginPlay()
{
	Super::BeginPlay();
}

void APowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto rot = GetActorRotation();
	auto eul = rot.Euler();
	auto asd = DeltaTime;

	eul.Y += RotationRate * DeltaTime;

	rot.MakeFromEuler(eul);
	SetActorRotation(rot);
}

