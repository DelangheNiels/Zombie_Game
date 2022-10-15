// Fill out your copyright notice in the Description page of Project Settings.


#include "Zone.h"

#include"../Zombies/Spawner.h"

#include "../FirstPersonCharacter.h"

#include "Components/BoxComponent.h"

// Sets default values
AZone::AZone()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AZone::BeginPlay()
{
	Super::BeginPlay();

	m_pCollisionBox = FindComponentByClass<UBoxComponent>();

	if (m_pCollisionBox)
	{
		m_pCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AZone::OnBeginOverlap);
		m_pCollisionBox->OnComponentEndOverlap.AddDynamic(this, &AZone::OnEndOverlap);
	}

}

// Called every frame
void AZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Get the amount of spawners that are in the zone
	if (!m_GotSpawners)
	{
		m_WaitTime += DeltaTime;
		if (m_WaitTime >= m_WaitTimer)
		{
			m_pCollisionBox->GetOverlappingActors(m_SpawnersInZone, ASpawner::StaticClass());
			m_GotSpawners = true;
		}
	}

	

}

bool AZone::GetIsPlayerInZone() const
{
	return m_IsPlayerInZone;
}

TArray<AActor*> AZone::GetSpawners() const
{
	return m_SpawnersInZone;
}


void AZone::OnBeginOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor->IsA<AFirstPersonCharacter>())
	{
		m_IsPlayerInZone = true;
		
	}
	
}

void AZone::OnEndOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{

	if (otherActor->IsA<AFirstPersonCharacter>())
	{
		m_IsPlayerInZone = false;
		
	}
	
}


