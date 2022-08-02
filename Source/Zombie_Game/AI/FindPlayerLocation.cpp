// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPlayerLocation.h"
#include "BlackboardKeys.h"

#include "../FirstPersonCharacter.h"

#include "../Zombies/BaseZombieAIController.h"
#include "../Zombies/BaseZombie.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

UFindPlayerLocation::UFindPlayerLocation(const FObjectInitializer& objectInitializer)
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UFindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	ABaseZombieAIController* controller = Cast<ABaseZombieAIController>(ownerComp.GetAIOwner());
	
	AFirstPersonCharacter* player = Cast<AFirstPersonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	controller->GetBlackboard()->SetValueAsVector(blackboardKeys::targetLocation, player->GetActorLocation());
	

	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}