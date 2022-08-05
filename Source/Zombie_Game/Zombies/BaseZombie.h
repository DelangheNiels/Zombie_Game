// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseCharacter.h"
#include "BaseZombie.generated.h"

/**
 * 
 */

class UBoxComponent;

UCLASS()
class ZOMBIE_GAME_API ABaseZombie : public ABaseCharacter
{
	GENERATED_BODY()

public:

	ABaseZombie();

protected:

	UPROPERTY(EditAnywhere, Category = "Zombie params")
		float m_Damage;

	float m_CurrentMovementSpeed;

	UPROPERTY(EditAnywhere, Category = "Zombie params")
		float m_WalkSpeed;

	bool m_CanSeePlayer;

	bool m_IsAttacking;

	bool m_IsInRange;

	UPROPERTY()
		UBoxComponent* m_pRightHandCollision;

	virtual void BeginPlay() override;

public:

	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintCallable)
		float GetWalkSpeed() const;

	void HasSeenPlayer(bool hasSeenPlayer);

	UFUNCTION(BlueprintCallable)
		bool GetCanSeenPlayer() const;

	void PlayAttackMontage();

	UFUNCTION(BlueprintCallable)
		bool GetIsAttacking() const;

	UFUNCTION(BlueprintCallable)
		void StopAttacking();

private:

	void SetRightHandCollision();

	UFUNCTION()
		void OnRightHandOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);
	
};
