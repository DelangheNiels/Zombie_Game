// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildUp.h"
#include "DirectorAI.h"
#include "Peak.h"

#include "../FirstPersonCharacter.h"

BuildUp::BuildUp()
	:DirectorAIState()
{
	m_ChangeDifficultyTimer = 0;
	m_OldPlayerIntensity = 0;
}

BuildUp::~BuildUp()
{
}

void BuildUp::HandleEnemySpawns(float deltaTime)
{
	if (m_pDirectorAI && m_pDirectorAI->GetPlayer())
	{
		m_ChangeDifficultyTimer += deltaTime;

		if (m_ChangeDifficultyTimer >= m_pDirectorAI->GetChangeDifficultyTime())
		{
			m_ChangeDifficultyTimer = 0;

			float intensityIncrease = m_pDirectorAI->GetPlayer()->GetIntensity() - m_OldPlayerIntensity;

			if (intensityIncrease >= m_pDirectorAI->GetIntensityToChangeDifficulty())
			{
				m_pDirectorAI->IncreaseAmountOfEnemies();
			}

			else
			{
				m_pDirectorAI->DecreaseAmountOfEnemies();
			}

			m_OldPlayerIntensity = m_pDirectorAI->GetPlayer()->GetIntensity();
		}
	}
	
}

void BuildUp::HandleStateChange(float)
{
	if (m_pDirectorAI)
	{
		if (m_pDirectorAI->GetPlayer()->GetIntensity() >= m_pDirectorAI->GetIntenstyToEnterPeak())
		{
			m_pDirectorAI->TransitionTo(new Peak());
		}
	}
	
}
