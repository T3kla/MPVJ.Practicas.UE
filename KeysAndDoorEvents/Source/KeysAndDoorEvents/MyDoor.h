#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MyDoor.generated.h"

UCLASS()
class KEYSANDDOOREVENTS_API AMyDoor : public AActor {
  GENERATED_BODY()

public:
  AMyDoor();

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
  USceneComponent *Root;

  // UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
  // USceneComponent *Hinge;

  // UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
  // UStaticMeshComponent *Frame;

  // UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
  // UStaticMeshComponent *Door;

  UPROPERTY(BlueprintReadOnly);
  bool IsOpen;

protected:
  virtual void BeginPlay() override;

public:
  virtual void Tick(float DeltaTime) override;

  UFUNCTION(BlueprintCallable)
  void ToggleOpen();

  UFUNCTION(BlueprintImplementableEvent)
  void StateChange(bool Status);
};
