// Fill out your copyright notice in the Description page of Project Settings.


#include "FindRandomLocation.h"

#include "BlackboardKeys.h"

#include "../Zombies/BaseZombieAIController.h"
#include "../Zombies/BaseZombie.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"

UFindRandomLocation::UFindRandomLocation(const FObjectInitializer& objectInitializer)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UFindRandomLocation::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	ABaseZombieAIController* controller = Cast<ABaseZombieAIController>(ownerComp.GetAIOwner());
	APawn* pawn = controller->GetPawn();

	FVector pawnLocation = pawn->GetActorLocation();

	//Find random location on navigation mesh
	FNavLocation randomLocation;
	UNavigationSystemV1* navigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (navigationSystem->GetRandomPointInNavigableRadius(pawnLocation, m_SearchRadius, randomLocation))
	{
		controller->GetBlackboard()->SetValueAsVector(blackboardKeys::targetLocation, randomLocation);
		
	}

	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
