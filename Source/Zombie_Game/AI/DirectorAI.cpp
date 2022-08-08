// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorAI.h"

#include "../FirstPersonCharacter.h"
#include "../Zones/Zone.h"
#include "../Zombies/Spawner.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "DirectorAIState.h"
#include "BuildUp.h"
#include "Peak.h"
#include "Relax.h"



ADirectorAI::ADirectorAI()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}

void ADirectorAI::BeginPlay()
{
	Super::BeginPlay();
	
	m_pPlayer = Cast<AFirstPersonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AZone::StaticClass(), m_Zones);

	m_pCurrentState = new BuildUp();
	m_pCurrentState->SetDirectorAI(this);

}

void ADirectorAI::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (m_pCurrentState)
	{
		m_pCurrentState->HandleEnemySpawns(deltaTime);
		m_pCurrentState->HandleStateChange(deltaTime);
	}
	

}

void ADirectorAI::TransitionTo(DirectorAIState* pState)
{
	if (m_pCurrentState)
		delete m_pCurrentState;

	m_pCurrentState = pState;
	m_pCurrentState->SetDirectorAI(this);
}

float ADirectorAI::GetChangeDifficultyTime() const
{
	return m_ChangeDifficultyTime;
}

float ADirectorAI::GetMaxEnemiesAlliveInLevel() const
{
	return m_MaxEnemiesAlliveInLevel;
}

float ADirectorAI::GetIntensityToChangeDifficulty() const
{
	return m_IntensityToChangeDifficulty;
}

float ADirectorAI::GetIntenstyToEnterPeak() const
{
	return m_IntensityToEnterPeak;
}

float ADirectorAI::GetPeakSpawnMultiplier() const
{
	return m_PeakSpawnMultiplier;
}

float ADirectorAI::GetRelaxTime() const
{
	return m_RelaxTime;
}

void ADirectorAI::IncreaseAmountOfEnemies()
{
	m_MaxEnemiesAlliveInLevel += (m_MaxEnemiesAlliveInLevel * (m_DifficultyMultiplier - 1));
}

void ADirectorAI::DecreaseAmountOfEnemies()
{
	m_MaxEnemiesAlliveInLevel -= (m_MaxEnemiesAlliveInLevel * (m_DifficultyMultiplier-1));
}

AFirstPersonCharacter* ADirectorAI::GetPlayer() const
{
	return m_pPlayer;
}

