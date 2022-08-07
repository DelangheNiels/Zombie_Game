// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DirectorAIState.h"

/**
 * 
 */
class ZOMBIE_GAME_API BuildUp : public DirectorAIState
{
public:
	BuildUp();
	virtual ~BuildUp();

	BuildUp(const BuildUp& other) = delete;
	BuildUp(BuildUp&& other) = delete;
	BuildUp& operator=(const BuildUp& other) = delete;
	BuildUp& operator=(BuildUp&& other) = delete;

	virtual void HandleEnemySpawns() override;

protected:

	
};
