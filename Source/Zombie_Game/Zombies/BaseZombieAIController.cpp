// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseZombieAIController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

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

	//m_pHearingConfig->HearingRange = 3000;
	
}

void ABaseZombieAIController::OnFPCharDetected(AActor* actor, FAIStimulus stimulus)
{
	AFirstPersonCharacter* player = Cast<AFirstPersonCharacter>(actor);

	ABaseZombie* pawn = Cast<ABaseZombie>(GetPawn());

	if (player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, TEXT("Has seen player"));
		m_pBlackboardComponent->SetValueAsBool(blackboardKeys::canSeePlayer, stimulus.WasSuccessfullySensed());

		if (pawn)
		{
			pawn->HasSeenPlayer(stimulus.WasSuccessfullySensed());
		}
	}
}

void ABaseZombieAIController::OnSoundSenseUpdate(const TArray<AActor*>& actors)
{
	for (size_t i = 0; i < actors.Num(); i++)
	{
		FActorPerceptionBlueprintInfo info;
		GetPerceptionComponent()->GetActorsPerception(actors[i], info);

		for (size_t j = 0; j < info.LastSensedStimuli.Num(); j++)
		{
			FAIStimulus stimulus = info.LastSensedStimuli[j];
			if (stimulus.Tag == "Sound")
			{
				GetBlackboardComponent()->SetValueAsBool(blackboardKeys::heardSound, true);
				GetBlackboardComponent()->SetValueAsVector(blackboardKeys::targetLocation, stimulus.StimulusLocation);
			}
		}
	}
}

void ABaseZombieAIController::SetupPerceptionSystem()
{

	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	//Sound
	m_pHearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Config"));

	m_pHearingConfig->HearingRange = 3000;
	m_pHearingConfig->DetectionByAffiliation.bDetectEnemies = true;
	m_pHearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
	m_pHearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ABaseZombieAIController::OnSoundSenseUpdate);
	GetPerceptionComponent()->ConfigureSense(*m_pHearingConfig);

	//Sight
	m_pSightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	m_pSightConfig->SightRadius = 1000;
	m_pSightConfig->LoseSightRadius = 1300;
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
