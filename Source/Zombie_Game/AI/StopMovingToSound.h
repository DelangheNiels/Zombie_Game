// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "StopMovingToSound.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ZOMBIE_GAME_API UStopMovingToSound : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UStopMovingToSound(const FObjectInitializer& objectInitializer);

protected:

public:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) override;
};
