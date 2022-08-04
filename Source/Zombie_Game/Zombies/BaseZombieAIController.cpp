// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseZombieAIController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AIPerceptionComponent.h"

#include "../AI/BlackboardKeys.h"

#include "BaseZombie.h"

#include "../FirstPersonCharacter.h"

ABaseZombieAIController::ABaseZombieAIController(const FObjectInitializer& objectInitializer)
{
	m_pBehaviorTreeComponent = objectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorTreeComponent"));
	
	m_pBlackboardComponent = objectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComponent"));

	SetupPerceptionSystem();

}

void ABaseZombieAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);
	bStartAILogicOnPossess = true;

	if (m_pBlackboardComponent)
	{
		m_pBlackboardComponent->InitializeBlackboard(*m_pBehaviorTree->BlackboardAsset);
	}
}

void ABaseZombieAIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(m_pBehaviorTree);
	m_pBehaviorTreeComponent->StartTree(*m_pBehaviorTree);

	SetupSightPerceptionParameters();
}

UBlackboardComponent* ABaseZombieAIController::GetBlackboard() const
{
	return m_pBlackboardComponent;
}

void ABaseZombieAIController::StopBehavior()
{
	BrainComponent->StopLogic("Dead");
}

void ABaseZombieAIController::SetupSightPerceptionParameters()
{
	m_pSightConfig->SightRadius = m_SightRadius;
	m_pSightConfig->LoseSightRadius = m_LoseSightRadius;
	m_pSightConfig->PeripheralVisionAngleDegrees = m_SightAngle;
	m_pSightConfig->SetMaxAge(m_MaxAge);
	m_pSightConfig->AutoSuccessRangeFromLastSeenLocation = m_SightSuccessRange;
	
}

void ABaseZombieAIController::OnFPCharDetected(AActor* actor, FAIStimulus stimulus)
{
	if (AFirstPersonCharacter* player = Cast<AFirstPersonCharacter>(actor))
	{
		m_pBlackboardComponent->SetValueAsBool(blackboardKeys::canSeePlayer, stimulus.WasSuccessfullySensed());

		if (auto pawn = Cast<ABaseZombie>(GetPawn()))
		{
			pawn->HasSeenPlayer(stimulus.WasSuccessfullySensed());
		}
	}
}

void ABaseZombieAIController::SetupPerceptionSystem()
{
	m_pSightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	m_pSightConfig->SightRadius = 1500;
	m_pSightConfig->LoseSightRadius = 2000;
	m_pSightConfig->PeripheralVisionAngleDegrees = 100;
	m_pSightConfig->SetMaxAge(5);
	m_pSightConfig->AutoSuccessRangeFromLastSeenLocation = 300;
	m_pSightConfig->DetectionByAffiliation.bDetectEnemies = true;
	m_pSightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	m_pSightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(m_pSightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseZombieAIController::OnFPCharDetected);
	GetPerceptionComponent()->ConfigureSense(*m_pSightConfig);
}
