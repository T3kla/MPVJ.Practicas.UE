#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyDoor.generated.h"


UCLASS()
class KEYSANDDOOREVENTS_API AMyDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyDoor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};