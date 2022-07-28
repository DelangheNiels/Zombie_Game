// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FirstPersonCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_GAME_API AFirstPersonCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	AFirstPersonCharacterController();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float deltaTime) override;

	virtual void SetupInputComponent() override;

private:

	class AFirstPersonCharacter* m_pCharacter;

	void HorizontalMovement(float axisValue);
	void VerticalMovement(float axisValue);
	void LookUpDown(float axisValue);
	void LookLeftRight(float axisValue);
	
};
