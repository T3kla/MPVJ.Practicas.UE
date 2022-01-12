#include "PowerUp.h"

APowerUp::APowerUp() {
    PrimaryActorTick.bCanEverTick = true;

    DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
    SphereTrigger =
        CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));

    SphereTrigger->SetSphereRadius(20);

    SetRootComponent(DefaultRoot);
    SphereTrigger->SetupAttachment(DefaultRoot);
}

void APowerUp::BeginPlay() { Super::BeginPlay(); }

void APowerUp::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    Time += DeltaTime;

    // Rotation
    auto rot = GetActorRotation();
    rot.Yaw += RotationRate * DeltaTime;
    SetActorRotation(rot);

    // Oscilation
    //if (!ensure(OscilationCurve))
    //    return;
    //
    //float MaxTime, MinTime;
    //OscilationCurve->GetTimeRange(MinTime, MaxTime);

    //float TimeInRange = fmod(Time, MaxTime);
    //float Height = OscilationCurve->GetFloatValue(TimeInRange);

    //FVector Location = GetActorLocation();
    //Location.Z = InitialZ + Height * OscilationAmplitude;

    //SetActorLocation(Location);

    //UE_LOG(LogTemp, Display, TEXT("Relative Location %0.3f %0.3f %0.3f")
    //    , Location.X, Location.Y, Location.Z);
}
