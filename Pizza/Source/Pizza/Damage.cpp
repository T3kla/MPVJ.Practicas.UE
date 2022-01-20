#include "Damage.h"

#include "PizzaCharacter.h"

ADamage::ADamage()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	Mesh->SetupAttachment(DefaultRoot);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(DefaultRoot);
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

void ADamage::TriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto *character = Cast<APizzaCharacter>(OtherActor);
	if (character)
	{
		Destroy();
		character->Damage();
	}
}
