// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAttack.h"

#include "../Zombies/BaseZombieAIController.h"
#include "../Zombies/BaseZombie.h"

UMeleeAttack::UMeleeAttack(const FObjectInitializer& objectInitializer)
{
	NodeName = TEXT("Melee Attack");
}

EBTNodeResult::Type UMeleeAttack::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	ABaseZombieAIController* controller = Cast<ABaseZombieAIController>(ownerComp.GetAIOwner());
	ABaseZombie* zombie = Cast<ABaseZombie>(controller->GetPawn());

	if (!zombie->GetIsAttacking())
	{
		zombie->PlayAttackMontage();
	}

	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
