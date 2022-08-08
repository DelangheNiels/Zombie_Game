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

	float GetChangeDifficultyTime() const;
	float GetMaxEnemiesAlliveInLevel() const;
	float GetIntensityToChangeDifficulty() const;
	float GetIntenstyToEnterPeak() const;
	float GetPeakSpawnMultiplier() const;
	float GetRelaxTime() const;

	void IncreaseAmountOfEnemies();
	void DecreaseAmountOfEnemies();

	AFirstPersonCharacter* GetPlayer() const;


private:

	UPROPERTY()
		AFirstPersonCharacter* m_pPlayer;

	TArray<AActor*> m_Zones;

	DirectorAIState* m_pCurrentState;

	//Variables in DirectorAI actor so that I can change the values in the editor and don't need to compile 
	UPROPERTY(EditAnywhere)
		float m_ChangeDifficultyTime = 20;

	UPROPERTY(EditAnywhere)
		float m_MaxEnemiesAlliveInLevel = 20;

	UPROPERTY(EditAnywhere)
		float m_DifficultyMultiplier = 1.2f;

	UPROPERTY(EditAnywhere)
		float m_IntensityToChangeDifficulty = 0.25f;

	UPROPERTY(EditAnywhere)
		float m_IntensityToEnterPeak = 1.0f;

	UPROPERTY(EditAnywhere)
		float m_PeakSpawnMultiplier = 1.5f;

	UPROPERTY(EditAnywhere)
		float m_RelaxTime = 20.0f;

};
