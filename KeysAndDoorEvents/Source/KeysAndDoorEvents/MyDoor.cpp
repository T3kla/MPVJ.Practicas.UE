#include "MyDoor.h"

AMyDoor::AMyDoor() {
  PrimaryActorTick.bCanEverTick = true;

  Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
  SetRootComponent(Root);

  // Hinge = CreateDefaultSubobject<USceneComponent>(TEXT("Hinge"));
  // Frame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
  // Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));

  // Door->SetupAttachment(Hinge)

  // Da igual lo que haga, no me deja hacer que Door sea child de Hinge, así
  // que toca hacerlo por blueprint
}

void AMyDoor::BeginPlay() {
  Super::BeginPlay();
  IsOpen = false;

  // Esto tampoco lo hace hijo
  // Door->AttachToComponent(Hinge, FAttachmentTransformRules::KeepWorldTransform);
}

void AMyDoor::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void AMyDoor::ToggleOpen() {
  IsOpen = !IsOpen;

  StateChange(IsOpen);
}
