// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorAI.h"

#include "../FirstPersonCharacter.h"
#include "../Zones/Zone.h"
#include "../Zombies/Spawner.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "DirectorAIState.h"
#include "BuildUp.h"
#include "Peak.h"
#include "Relax.h"



ADirectorAI::ADirectorAI()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	m_pCurrentState = new BuildUp();

}

void ADirectorAI::BeginPlay()
{
	Super::BeginPlay();
	
	m_pPlayer = Cast<AFirstPersonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AZone::StaticClass(), m_Zones);

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("%i"), m_Zones.Num()));
}

void ADirectorAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_pCurrentState->HandleEnemySpawns();

	m_TransitionTimer += DeltaTime;
	if (m_TransitionTimer >= 5)
	{
		m_TransitionTimer = 0;
		
		TransitionTo(new Peak());
	}

}

void ADirectorAI::TransitionTo(DirectorAIState* pState)
{
	if (m_pCurrentState)
		delete m_pCurrentState;

	m_pCurrentState = pState;
	m_pCurrentState->SetDirectorAI(this);
}

