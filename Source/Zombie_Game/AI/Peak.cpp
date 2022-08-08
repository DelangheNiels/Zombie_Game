// Fill out your copyright notice in the Description page of Project Settings.


#include "Peak.h"
#include "Relax.h"
#include "DirectorAI.h"


#include "../FirstPersonCharacter.h"

Peak::Peak()
	:DirectorAIState()
{
}

Peak::~Peak()
{
}

void Peak::HandleEnemySpawns(float deltaTime)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("In Peak"));
}

void Peak::HandleStateChange(float deltaTime)
{
	if (m_pDirectorAI->GetNrEnemiesAllive() <= 0)
	{
		m_pDirectorAI->TransitionTo(new Relax());
	}
		
}
