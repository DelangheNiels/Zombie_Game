// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MeleeAttack.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_GAME_API UMeleeAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UMeleeAttack(const FObjectInitializer& objectInitializer);

protected:

public:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) override;
};
