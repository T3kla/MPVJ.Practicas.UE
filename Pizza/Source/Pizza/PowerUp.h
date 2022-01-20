#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "PowerUp.generated.h"

UCLASS()
class PIZZA_API APowerUp : public AActor
{
	GENERATED_BODY()
	
private:
	double Time = 0.;
	float InitialZ = 0.f;

public:	
	UPROPERTY(EditAnywhere);
		float RotationRate = 180.f;

	UPROPERTY(EditAnywhere);
		float OscilationRate = 180.f;

	UPROPERTY(EditAnywhere);
		float OscilationAmplitude = 100.f;

	UPROPERTY(EditAnywhere);
		UCurveFloat* OscilationCurve;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* DefaultRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* SphereTrigger;


	APowerUp();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Damage")
		void PickupPowerUp(AActor* OtherActor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Damage")
		void OnPickupPowerUpDoneEvent();
};
