// Fill out your copyright notice in the Description page of Project Settings.


#include "Relax.h"
#include "BuildUp.h"
#include "DirectorAI.h"

#include "../FirstPersonCharacter.h"

Relax::Relax()
	:DirectorAIState()
{
	m_RelaxTimer = 0;
}

Relax::~Relax()
{
}

void Relax::HandleEnemySpawns(float deltaTime)
{
	//No enemies spawn during relax state
}

void Relax::HandleStateChange(float deltaTime)
{
	if (m_pDirectorAI)
	{
		m_RelaxTimer += deltaTime;
		if (m_RelaxTimer >= m_pDirectorAI->GetRelaxTime())
		{
			m_pDirectorAI->TransitionTo(new BuildUp());
			m_pDirectorAI->GetPlayer()->ResetIntensity();
		}
	}
}

FString Relax::GetStateName() const
{
	return "Relax";
}
