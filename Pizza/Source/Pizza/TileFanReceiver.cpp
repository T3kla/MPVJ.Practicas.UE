#include "TileFanReceiver.h"

ATileFanReceiver::ATileFanReceiver()
{
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComponent);

	BladeStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BladeStaticMesh"));
	BladeStaticMesh->SetupAttachment(RootSceneComponent);
	BladeStaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ATileFanReceiver::BeginPlay()
{
	Super::BeginPlay();

	if (TileStep)
	{
		TileStep->SteppedEvent.AddDynamic(this,&ATileFanReceiver::OnTileTriggered);
	}
}

void ATileFanReceiver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsRotating)
	{
		Time += DeltaTime;
		Time = Time > 1 ? 0 : Time;
		FRotator Rotator;
		float Speed = 3;
		Rotator.Roll = Time * Speed * 360.f;
		BladeStaticMesh->SetRelativeRotation(Rotator);
		UE_LOG(LogTemp, Warning, TEXT("Rotating: %0.3f\n"), Rotator.Roll);
	}
}

void ATileFanReceiver::OnTileTriggered(AActor* actor, bool InOut)
{
	IsRotating = !IsRotating;
}

