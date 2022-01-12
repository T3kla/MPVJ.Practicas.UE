#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TileStep.h"
#include "TileFanReceiver.generated.h"

UCLASS()
class PIZZA_API ATileFanReceiver : public AActor
{
	GENERATED_BODY()
	
private:
	double Time = 0.;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
		USceneComponent* RootSceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
		UStaticMeshComponent* BladeStaticMesh;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
		ATileStep* TileStep;

	UPROPERTY(EditAnywhere);
		bool IsRotating;

	UFUNCTION()
		void OnTileTriggered(AActor* actor, bool InOut);

	ATileFanReceiver();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
