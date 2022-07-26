// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicGun.h"
#include "Gun_AK.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_GAME_API AGun_AK : public ABasicGun
{
	GENERATED_BODY()

public:

	AGun_AK();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float deltaTime) override;
	
};
