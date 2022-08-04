// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ZOMBIE_GAME_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		float GetCurrentHealth() const;
	float GetMaxHealth() const;
	float GetHealthPercentage()const;

protected:

	UPROPERTY()
		float m_CurrentHealth;

	UPROPERTY(EditAnywhere, Category = "Player Health")
		float m_MaxHealth = 100;

private:


};
