#include "TileStep.h"

ATileStep::ATileStep()
{
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootSceneComponent);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(RootSceneComponent);
}

void ATileStep::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ATileStep::OnStepIn);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &ATileStep::OnStepOut);
}

void ATileStep::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATileStep::OnStepIn(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Display, TEXT("SteppedIn"));
	SteppedEvent.Broadcast(Other, true);
}

void ATileStep::OnStepOut(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Display, TEXT("SteppedOut"));
	SteppedEvent.Broadcast(Other, false);
}

