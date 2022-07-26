// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DirectorAIState.h"

/**
 * 
 */
class ZOMBIE_GAME_API Peak : public DirectorAIState
{
public:
	Peak();
	~Peak();

	Peak(const Peak& other) = delete;
	Peak(Peak&& other) = delete;
	Peak& operator=(const Peak& other) = delete;
	Peak& operator=(Peak&& other) = delete;

	virtual void HandleEnemySpawns(float DeltaTime) override;
	virtual void HandleStateChange(float deltaTime) override;
	virtual FString GetStateName() const override;

protected:

private:

	bool m_HasSpawnedEnemies;
};
