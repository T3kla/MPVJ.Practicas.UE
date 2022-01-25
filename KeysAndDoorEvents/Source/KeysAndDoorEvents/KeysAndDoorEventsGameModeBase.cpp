#include "KeysAndDoorEventsGameModeBase.h"

AKeysAndDoorEventsGameModeBase::AKeysAndDoorEventsGameModeBase()
{
}

void AKeysAndDoorEventsGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // Search Keys
    TArray<AActor *> KeyArray;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyKey::StaticClass(), KeyArray);

    TotalKeys = KeyArray.Num();

    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
                                         FString::Printf(TEXT("KeyArray has %d keys."), TotalKeys));

    // Subscribe to key's event
    for (auto &&i : KeyArray)
        Cast<AMyKey>(i)->KeyOverlapEvent.AddDynamic(
            this, &AKeysAndDoorEventsGameModeBase::OnKeyRetrieved);
}

void AKeysAndDoorEventsGameModeBase::OnKeyRetrieved()
{
    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Key Retrieved");

    CurrentKeys++;

    // If retrieved all keys in the level
    if (CurrentKeys < TotalKeys)
        return;

    TArray<AActor *> DoorArray;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyDoor::StaticClass(), DoorArray);

    if (GEngine)
        GEngine->AddOnScreenDebugMessage(
            -1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Opening %d doors."), DoorArray.Num()));

    for (auto &&i : DoorArray)
        Cast<AMyDoor>(i)->ToggleOpen();
}
