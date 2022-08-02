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
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> bTree(TEXT("BehaviorTree'/Game/Blueprints/Zombies/WanderZombie/AI/BT_WanderZombie.BT_WanderZombie'"));
	if (bTree.Succeeded())
		m_pBehaviorTree = bTree.Object;

	m_pBehaviorTreeComponent = objectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorTreeComponent"));
	
	m_pBlackboardComponent = objectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComponent"));

	SetupPerceptionSystem();

}

void ABaseZombieAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	if (m_pBlackboardComponent)
	{
		m_pBlackboardComponent->InitializeBlackboard(*m_pBehaviorTree->BlackboardAsset);
	}
}

void ABaseZombieAIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
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

void ABaseZombieAIController::SetupSightPerceptionParameters()
{
	m_pSightConfig->SightRadius = m_SightRadius;
	m_pSightConfig->LoseSightRadius = m_LoseSightRadius;
	m_pSightConfig->PeripheralVisionAngleDegrees = m_SightAngle;
	m_pSightConfig->SetMaxAge(m_MaxAge);
	m_pSightConfig->AutoSuccessRangeFromLastSeenLocation = m_SightSuccessRange;
	m_pSightConfig->DetectionByAffiliation.bDetectEnemies = true;
	m_pSightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	m_pSightConfig->DetectionByAffiliation.bDetectNeutrals = true;
}

void ABaseZombieAIController::OnPlayerDetected(AActor* actor, FAIStimulus stimulus)
{
	if (AFirstPersonCharacter* player = Cast<AFirstPersonCharacter>(actor))
	{
		m_pBlackboardComponent->SetValueAsBool(blackboardKeys::canSeePlayer, stimulus.WasSuccessfullySensed());
	}
}

void ABaseZombieAIController::SetupPerceptionSystem()
{
	m_pSightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	GetPerceptionComponent()->SetDominantSense(m_pSightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseZombieAIController::OnPlayerDetected);
	GetPerceptionComponent()->ConfigureSense(*m_pSightConfig);
}
