// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseZombie.h"
#include "BasicZombie.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_GAME_API ABasicZombie : public ABaseZombie
{
	GENERATED_BODY()

public:

	ABasicZombie();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float deltaTime) override;
	
};
