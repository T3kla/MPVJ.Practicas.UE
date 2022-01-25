#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"
#include "MyDoor.h"
#include "MyKey.h"
#include "Kismet/GameplayStatics.h"
#include "KeysAndDoorEventsGameModeBase.generated.h"

UCLASS()
class KEYSANDDOOREVENTS_API AKeysAndDoorEventsGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

    int TotalKeys = 0;
    int CurrentKeys = 0;

  public:
    AKeysAndDoorEventsGameModeBase();

    UFUNCTION()
    void OnKeyRetrieved();

    virtual void BeginPlay() override;
};
