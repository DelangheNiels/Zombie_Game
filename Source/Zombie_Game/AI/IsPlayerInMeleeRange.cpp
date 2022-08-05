// Fill out your copyright notice in the Description page of Project Settings.


#include "IsPlayerInMeleeRange.h"
#include "BlackboardKeys.h"

#include "../Zombies/BaseZombieAIController.h"
#include "../Zombies/BaseZombie.h"

#include "../FirstPersonCharacter.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "BehaviorTree/BlackboardComponent.h"


UIsPlayerInMeleeRange::UIsPlayerInMeleeRange()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Is Player In Melee Range");
}

void UIsPlayerInMeleeRange::OnBecomeRelevant(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	Super::OnBecomeRelevant(ownerComp, nodeMemory);

	ABaseZombieAIController* controller = Cast<ABaseZombieAIController>(ownerComp.GetAIOwner());
	ABaseZombie* zombie = Cast<ABaseZombie>(controller->GetPawn());

	AFirstPersonCharacter* player = Cast<AFirstPersonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	controller->GetBlackboard()->SetValueAsBool(blackboardKeys::isPlayerInRange, zombie->GetDistanceTo(player) <=  m_MeleeRange);

}
