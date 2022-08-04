// Fill out your copyright notice in the Description page of Project Settings.


#include "StopMovingToSound.h"
#include "BlackboardKeys.h"

#include "BehaviorTree/BlackboardComponent.h"

#include "../Zombies/BaseZombieAIController.h"

UStopMovingToSound::UStopMovingToSound(const FObjectInitializer& objectInitializer)
{
	NodeName = TEXT("Stop Moving To Sound");
}

EBTNodeResult::Type UStopMovingToSound::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	ABaseZombieAIController* controller = Cast<ABaseZombieAIController>(ownerComp.GetAIOwner());
	controller->GetBlackboardComponent()->SetValueAsBool(blackboardKeys::heardSound, false);
	
	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
