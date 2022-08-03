// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalZombieAIController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AIPerceptionComponent.h"

#include "../AI/BlackboardKeys.h"

#include "BaseZombie.h"

#include "../FirstPersonCharacter.h"

ANormalZombieAIController::ANormalZombieAIController(const FObjectInitializer& objectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> bTree(TEXT("BehaviorTree'/Game/Blueprints/Zombies/NormalZombie/AI/BT_NormalZombie.BT_NormalZombie'"));
	if (bTree.Succeeded())
		m_pBehaviorTree = bTree.Object;

	//bStartAILogicOnPossess = true;

}

void ANormalZombieAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);
}

void ANormalZombieAIController::BeginPlay()
{
	Super::BeginPlay();
}

