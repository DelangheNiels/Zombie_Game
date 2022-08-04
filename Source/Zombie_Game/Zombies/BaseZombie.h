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

	UPROPERTY(EditAnywhere, Category = "Zombie params")
		float m_WalkSpeed;

	bool m_CanSeePlayer;

	virtual void BeginPlay() override;

public:

	virtual void Tick(float deltaTime) override;

	void Damage(float damage);

	UFUNCTION(BlueprintCallable)
		float GetWalkSpeed() const;

	void HasSeenPlayer(bool hasSeenPlayer);

	UFUNCTION(BlueprintCallable)
		bool GetCanSeenPlayer() const;

private:

	
};
