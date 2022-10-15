// Fill out your copyright notice in the Description page of Project Settings.


#include "Peak.h"
#include "Relax.h"
#include "DirectorAI.h"

#include "../Zones/Zone.h"

#include "../Zombies/Spawner.h"

#include "../FirstPersonCharacter.h"

Peak::Peak()
	:DirectorAIState()
{
}

Peak::~Peak()
{
}

void Peak::HandleEnemySpawns(float)
{
	if (m_pDirectorAI && !m_HasSpawnedEnemies)
	{
		
		AZone* zone = m_pDirectorAI->GetActiveZone();

		int nrEnemiesToSpawn = m_pDirectorAI->GetMaxEnemiesAlliveInLevel() * m_pDirectorAI->GetPeakSpawnMultiplier();
		

		if (zone)
		{
			for (size_t i = 0; i < nrEnemiesToSpawn; i++)
			{
				int spawnerNr = FMath::RandRange(0, zone->GetSpawners().Num() - 1);

				ASpawner* spawner = Cast<ASpawner>(zone->GetSpawners()[spawnerNr]);
				spawner->Spawn();
			}
		}

		m_HasSpawnedEnemies = true;
	}
}

void Peak::HandleStateChange(float)
{
	if (m_pDirectorAI->GetNrEnemiesAllive() <= 0)
	{
		
		m_pDirectorAI->TransitionTo(new Relax());
	}
		
}

FString Peak::GetStateName() const
{
	return "Peak";
}
