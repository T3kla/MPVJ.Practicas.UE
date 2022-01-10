// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpActorCpp.h"

// Sets default values
APickUpActorCpp::APickUpActorCpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));
	OscilateComponent = CreateDefaultSubobject<UOscilateComponent>(TEXT("OscilateComponent"));

	SetRootComponent(DefaultRoot);
	SphereTrigger->SetupAttachment(DefaultRoot);
	OscilateComponent->SetupAttachment(DefaultRoot);
	StaticMesh->SetupAttachment(OscilateComponent);
}

// Called when the game starts or when spawned
void APickUpActorCpp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpActorCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

