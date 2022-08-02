// Fill out your copyright notice in the Description page of Project Settings.


#include "ChasePlayer.h"
#include "BlackboardKeys.h"

#include "../Zombies/BaseZombieAIController.h"

#include "BehaviorTree/BlackboardComponent.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"

UChasePlayer::UChasePlayer(const FObjectInitializer& objectInitializer)
{
	NodeName = TEXT("Chase Player");
}

EBTNodeResult::Type UChasePlayer::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	ABaseZombieAIController* controller = Cast<ABaseZombieAIController>(ownerComp.GetAIOwner());

	FVector playerLocation = controller->GetBlackboard()->GetValueAsVector(blackboardKeys::targetLocation);

	//Move to player
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(controller, playerLocation);

	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}