#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MyDoor.generated.h"


UCLASS()
class KEYSANDDOOREVENTS_API AMyDoor : public AActor
{
	GENERATED_BODY()

public:	
	AMyDoor();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
	USceneComponent* RootSceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
	UStaticMeshComponent* Frame;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
	UStaticMeshComponent* Door;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
