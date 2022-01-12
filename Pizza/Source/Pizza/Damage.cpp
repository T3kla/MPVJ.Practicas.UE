#include "Damage.h"

ADamage::ADamage()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	Mesh->SetupAttachment(RootSceneComponent);
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(RootSceneComponent);
}

void ADamage::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ADamage::TriggerEnter);
}

void ADamage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADamage::OnTriggerEnter()
{
}