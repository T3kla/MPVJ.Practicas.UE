// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Camera/CameraActor.h"
#include "CamSwitchLevelScriptActor.generated.h"

UCLASS()
class INTRO_API ACamSwitchLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<AActor*> LevelCameras;

public:

	void BeginPlay() override;

	UFUNCTION()
		void OnFirePressed();

private:
	int32 Counter;
	
	void ChangeCamera();
};
