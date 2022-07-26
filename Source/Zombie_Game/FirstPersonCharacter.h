// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "FirstPersonCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_GAME_API AFirstPersonCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	AFirstPersonCharacter();

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;

	void HorizontalMovement(float axisValue);
	void VerticalMovement(float axisValue);

private:

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* m_pCamera;
	
};
