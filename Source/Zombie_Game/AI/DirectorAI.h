// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DirectorAI.generated.h"

class AFirstPersonCharacter;
class AZone;
class DirectorAIState;

UCLASS()
class ZOMBIE_GAME_API ADirectorAI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectorAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TransitionTo(DirectorAIState* pState);

private:

	UPROPERTY()
		AFirstPersonCharacter* m_pPlayer;

	TArray<AActor*> m_Zones;

	DirectorAIState* m_pCurrentState;

	float m_TransitionTimer = 0;
};
