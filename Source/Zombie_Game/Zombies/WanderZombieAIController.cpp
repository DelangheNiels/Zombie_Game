// Fill out your copyright notice in the Description page of Project Settings.


#include "WanderZombieAIController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AIPerceptionComponent.h"

#include "../AI/BlackboardKeys.h"

#include "BaseZombie.h"

#include "../FirstPersonCharacter.h"

AWanderZombieAIController::AWanderZombieAIController(const FObjectInitializer& objectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> bTree(TEXT("BehaviorTree'/Game/Blueprints/Zombies/WanderZombie/AI/BT_WanderZombie.BT_WanderZombie'"));
	if (bTree.Succeeded())
		m_pBehaviorTree = bTree.Object;

	bStartAILogicOnPossess = true;

}

void AWanderZombieAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);
}

void AWanderZombieAIController::BeginPlay()
{
	Super::BeginPlay();
}
