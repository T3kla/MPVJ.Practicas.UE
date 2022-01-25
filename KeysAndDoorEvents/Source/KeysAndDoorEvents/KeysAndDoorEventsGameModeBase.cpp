#include "KeysAndDoorEventsGameModeBase.h"

AKeysAndDoorEventsGameModeBase::AKeysAndDoorEventsGameModeBase()
{
}

void AKeysAndDoorEventsGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // Buscar llaves
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyKey::StaticClass(), KeyArray);

    // Buscar puertas
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyDoor::StaticClass(), DoorArray);

    // Debug Arrays
    if (GEngine)
        GEngine->AddOnScreenDebugMessage(
            -1, 15.0f, FColor::Yellow,
            FString::Printf(TEXT("KeyArray has %d keys.\n DoorArray has %d doors."), KeyArray.Num(),
                            DoorArray.Num()));

    // Subscribe to key's event
    for (auto &i : KeyArray)
        Cast<AMyKey>(i)->KeyOverlapEvent.AddDynamic(
            this, &AKeysAndDoorEventsGameModeBase::OnKeyRetrieved);
}

void AKeysAndDoorEventsGameModeBase::OnKeyRetrieved()
{
    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Lmao");

    // Check if keys retrieved >= keys total
}
