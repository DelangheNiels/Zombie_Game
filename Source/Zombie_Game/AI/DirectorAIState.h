// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

class ADirectorAI;

class ZOMBIE_GAME_API DirectorAIState
{
public:
	DirectorAIState();
	virtual ~DirectorAIState();

	DirectorAIState(const DirectorAIState& other) = delete;
	DirectorAIState(DirectorAIState&& other) = delete;
	DirectorAIState& operator=(const DirectorAIState& other) = delete;
	DirectorAIState& operator=(DirectorAIState&& other) = delete;

	void SetDirectorAI(ADirectorAI* pDirectorAI);

	virtual void HandleEnemySpawns(float deltaTime) = 0;
	virtual void HandleStateChange(float deltaTime) = 0;
	virtual FString GetStateName() const = 0;

protected:

	ADirectorAI* m_pDirectorAI;


};
