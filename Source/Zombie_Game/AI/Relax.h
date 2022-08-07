// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DirectorAIState.h"
/**
 * 
 */
class ZOMBIE_GAME_API Relax : public DirectorAIState
{
public:
	Relax();
	~Relax();

	Relax(const Relax& other) = delete;
	Relax(Relax&& other) = delete;
	Relax& operator=(const Relax& other) = delete;
	Relax& operator=(Relax&& other) = delete;

	virtual void HandleEnemySpawns() override;

protected:

};
