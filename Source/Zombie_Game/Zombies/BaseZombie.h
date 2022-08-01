// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseCharacter.h"
#include "BaseZombie.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_GAME_API ABaseZombie : public ABaseCharacter
{
	GENERATED_BODY()

public:

	ABaseZombie();

protected:

	UPROPERTY(EditAnywhere, Category = "Zombie params")
		float m_Damage;

	virtual void BeginPlay() override;

public:

	virtual void Tick(float deltaTime) override;
	
};