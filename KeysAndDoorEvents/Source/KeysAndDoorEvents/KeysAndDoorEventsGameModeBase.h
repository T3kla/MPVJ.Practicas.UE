#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "KeysAndDoorEventsGameModeBase.generated.h"

UCLASS()
class KEYSANDDOOREVENTS_API AKeysAndDoorEventsGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

  public:
    AKeysAndDoorEventsGameModeBase();

    virtual void BeginPlay() override;
};
