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

    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyKey::OnOverlap);
}

void AMyKey::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyKey::OnOverlap(UPrimitiveComponent *OverlappedComp, AActor *Other,
                       UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                       const FHitResult &SweepResult)
{
    Broadcast();
}

void AMyKey::Broadcast()
{
    UE_LOG(LogTemp, Display, TEXT("OnOverlap"));
    KeyOverlapEvent.Broadcast();
    Destroy();
}