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
			m_pCollisionBox->GetOverlappingActors(m_pSpawnersInZone, ASpawner::StaticClass());
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("amount of spawners in zone: %i"), m_pSpawnersInZone.Num()));
			m_GotSpawners = true;
		}
	}

	

}

void AZone::OnBeginOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor->IsA<AFirstPersonCharacter>())
	{
		m_IsPlayerInZone = true;
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Player entered zone"));
	}
	
}

void AZone::OnEndOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{

	if (otherActor->IsA<AFirstPersonCharacter>())
	{
		m_IsPlayerInZone = false;
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Player left zone"));
	}
	
}


