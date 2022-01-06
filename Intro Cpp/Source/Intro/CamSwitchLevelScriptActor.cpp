// Fill out your copyright notice in the Description page of Project Settings.


#include "CamSwitchLevelScriptActor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ACamSwitchLevelScriptActor::BeginPlay()
{
	TArray<AActor*> AllCameras;
	UGameplayStatics::GetAllActorsOfClass(this, ACameraActor::StaticClass(), AllCameras);

	for (auto Camera : AllCameras) {
		if (Camera->ActorHasTag("RigidCam")) {
			LevelCameras.Add(Camera);
			UE_LOG(LogTemp, Warning, TEXT("Added Camera: %s"), *Camera->GetName());
		}
	}
	ensure(LevelCameras.Num() > 0);

	Counter = 0;

	InputComponent->BindAction("Fire", IE_Released, this, &ACamSwitchLevelScriptActor::OnFirePressed);

	Super::BeginPlay();
	LoopThroughCameras(2.f);
}

void ACamSwitchLevelScriptActor::OnFirePressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Pressed"));
	ChangeCamera();
	Counter = (Counter + 1) % LevelCameras.Num();
}

void ACamSwitchLevelScriptActor::DoChangeCamera()
{
	UE_LOG(LogTemp, Warning, TEXT("Do ChangeCamera"));
	ChangeCamera();
	ShowCameraName(static_cast<ACameraActor*>(LevelCameras[Counter]));
	Counter = (Counter + 1) % LevelCameras.Num();
}

void ACamSwitchLevelScriptActor::LoopThroughCameras_Implementation(float timelapse)
{
	UWorld * World = GEngine->GameViewport->GetWorld();

	FTimerHandle Handle;

	World->GetTimerManager().SetTimer(
		Handle,
		this,
		&ACamSwitchLevelScriptActor::DoChangeCamera,
		timelapse,
		true,
		0.f);
}

void ACamSwitchLevelScriptActor::ChangeCamera()
{
	if (LevelCameras.Num() > 0) {
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		PlayerController->SetViewTargetWithBlend(LevelCameras[Counter], 1);
	}
}
