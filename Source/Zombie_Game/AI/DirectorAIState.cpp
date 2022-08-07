// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorAIState.h"
#include "DirectorAI.h"

DirectorAIState::DirectorAIState()
{
}

DirectorAIState::~DirectorAIState()
{
}

void DirectorAIState::SetDirectorAI(ADirectorAI* pDirectorAI)
{
	m_pDirectorAI = pDirectorAI;
}
