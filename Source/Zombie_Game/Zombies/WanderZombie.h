// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseZombie.h"
#include "WanderZombie.generated.h"

/**
 * 
 */

class UBoxComponent;

UCLASS()
class ZOMBIE_GAME_API AWanderZombie : public ABaseZombie
{
	GENERATED_BODY()

public:

	AWanderZombie();

protected:

	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
		float GetRunSpeed() const;

	virtual void Tick(float deltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = "Zombie params")
		float m_RunSpeed;
	
};
