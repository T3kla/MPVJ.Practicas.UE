#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/DelegateCombinations.h"
#include "Components/SphereComponent.h"
#include "MyKey.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FKeyOverlap);

UCLASS()
class KEYSANDDOOREVENTS_API AMyKey : public AActor
{
    GENERATED_BODY()

  public:
    AMyKey();

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
    USceneComponent *RootSceneComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
    USphereComponent *SphereComponent;

    UPROPERTY(BlueprintAssignable);
    FKeyOverlap KeyOverlapEvent;

  protected:
    virtual void BeginPlay() override;

  public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void OnOverlap(UPrimitiveComponent *OverlappedComp, AActor *Other,
                   UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                   const FHitResult &SweepResult);

  private:
    void Broadcast();
};
