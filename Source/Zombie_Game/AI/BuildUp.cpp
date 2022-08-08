// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildUp.h"
#include "DirectorAI.h"
#include "Peak.h"

#include "../Zones/Zone.h"

#include "../Zombies/Spawner.h"

#include "../FirstPersonCharacter.h"

BuildUp::BuildUp()
	:DirectorAIState()
{
	m_ChangeDifficultyTimer = 0;
	m_OldPlayerIntensity = 0;
	m_TimeToSpawnEnemiesTimer = 0;
}

BuildUp::~BuildUp()
{
}

void BuildUp::HandleEnemySpawns(float deltaTime)
{
	if (m_pDirectorAI && m_pDirectorAI->GetPlayer())
	{
		SpawnEnemies(deltaTime);
		ChangeDifficulty(deltaTime);
	}
	
}

void BuildUp::HandleStateChange(float)
{
	if (m_pDirectorAI)
	{
		if (m_pDirectorAI->GetPlayer()->GetIntensity() >= m_pDirectorAI->GetIntenstyToEnterPeak())
		{
			m_pDirectorAI->TransitionTo(new Peak());
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("To Peak"));
		}
	}
	
}

void BuildUp::SpawnEnemies(float deltaTime)
{
	AZone* zone = m_pDirectorAI->GetActiveZone();

	int nrEnemiesToSpawn = m_pDirectorAI->GetMaxEnemiesAlliveInLevel() - m_pDirectorAI->GetNrEnemiesAllive();

	m_TimeToSpawnEnemiesTimer += deltaTime;
	if (m_TimeToSpawnEnemiesTimer >= m_pDirectorAI->GetTimeToSpawnEnemies())
	{
		if (zone && nrEnemiesToSpawn > 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("%i"), nrEnemiesToSpawn));
			for (size_t i = 0; i < nrEnemiesToSpawn; i++)
			{
				int spawnerNr = FMath::RandRange(0, zone->GetSpawners().Num() - 1);

				ASpawner* spawner = Cast<ASpawner>(zone->GetSpawners()[spawnerNr]);
				spawner->Spawn();
			}
		}

		m_TimeToSpawnEnemiesTimer = 0;
	}
	
}

void BuildUp::ChangeDifficulty(float deltaTime)
{
	m_ChangeDifficultyTimer += deltaTime;

	if (m_ChangeDifficultyTimer >= m_pDirectorAI->GetChangeDifficultyTime())
	{
		m_ChangeDifficultyTimer = 0;

		float intensityIncrease = m_pDirectorAI->GetPlayer()->GetIntensity() - m_OldPlayerIntensity;

		if (intensityIncrease < m_pDirectorAI->GetIntensityToChangeDifficulty())
		{
			m_pDirectorAI->IncreaseAmountOfEnemiesToSpawn();
		}

		else
		{
			m_pDirectorAI->DecreaseAmountOfEnemiesToSpawn();
		}

		m_OldPlayerIntensity = m_pDirectorAI->GetPlayer()->GetIntensity();
	}
}
