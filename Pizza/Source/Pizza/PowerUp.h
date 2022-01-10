#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "PowerUp.generated.h"

UCLASS()
class PIZZA_API APowerUp : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere);
	float RotationRate = 180.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* DefaultRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* SphereTrigger;

	APowerUp();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
