// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Delegates/DelegateCombinations.h"
#include "TileStep.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSteppedTileEventSignature, AActor*, OverlappedActor, bool, InOut);

UCLASS()
class PIZZA_API ATileStep : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
		USceneComponent* RootSceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
		UBoxComponent* BoxComponent;

	UPROPERTY(BlueprintAssignable, Category = "Tile")
		FSteppedTileEventSignature SteppedEvent;

	ATileStep();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnStepIn(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnStepOut(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
