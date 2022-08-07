// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseCharacter.h"
#include "BaseZombie.generated.h"

/**
 * 
 */

class UBoxComponent;
class AFirstPersonCharacter;

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

	UPROPERTY()
		AFirstPersonCharacter* m_pPlayer;

	virtual void BeginPlay() override;

	virtual void TookDamage(float damage) override;

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

	UPROPERTY(EditAnywhere, Category = "Zombie params")
		float m_CloseByRange;

	UPROPERTY(EditAnywhere, Category = "Zombie params")
		float m_IntensityWhenKilledFromFarRange;

	UPROPERTY(EditAnywhere, Category = "Zombie params")
		float m_IntensityWhenKilledFromCloseRange;

	UPROPERTY(EditAnywhere, Category = "Zombie params")
		float m_IntensityWhenHittingPlayer;

	void SetRightHandCollision();

	UFUNCTION()
		void OnRightHandOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);
	
};
