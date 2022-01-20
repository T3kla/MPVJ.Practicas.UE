// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/DelegateCombinations.h"
#include "Components/SphereComponent.h"
#include "MyKey.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNombreRandom, const FString&, ParametroRandom);

UCLASS()
class KEYSANDDOOREVENTS_API AMyKey : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyKey();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
	USceneComponent* RootSceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
	USphereComponent* SphereComponent;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};