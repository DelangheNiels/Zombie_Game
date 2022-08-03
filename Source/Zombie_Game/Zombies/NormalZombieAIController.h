// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseZombieAIController.h"
#include "NormalZombieAIController.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_GAME_API ANormalZombieAIController : public ABaseZombieAIController
{
	GENERATED_BODY()

public:

	ANormalZombieAIController(const FObjectInitializer& objectInitializer = FObjectInitializer::Get());

protected:

	UPROPERTY(EditAnywhere, Category = "Behavior Tree")
		UBehaviorTree* m_pBehaviorTreeVar;

	virtual void OnPossess(APawn* pawn) override;

public:

	virtual void BeginPlay() override;

};
