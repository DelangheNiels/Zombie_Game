// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseZombieAIController.h"
#include "WanderZombieAIController.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_GAME_API AWanderZombieAIController : public ABaseZombieAIController
{
	GENERATED_BODY()

public:

	AWanderZombieAIController(const FObjectInitializer& objectInitializer = FObjectInitializer::Get());

protected:

	virtual void OnPossess(APawn* pawn) override;

public:

	virtual void BeginPlay() override;
	
};
