// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseZombie.h"
#include "BaseZombieAIController.h"

#include "../Bullets/BasicBullet.h"

#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

ABaseZombie::ABaseZombie()
{
	m_CanSeePlayer = false;
}

void ABaseZombie::BeginPlay()
{
	Super::BeginPlay();
	
	GetCharacterMovement()->MaxWalkSpeed = m_WalkSpeed;
}

void ABaseZombie::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (m_CurrentHealth <= 0)
	{
		GetCharacterMovement()->MaxWalkSpeed = 0;
		ABaseZombieAIController* controller = Cast<ABaseZombieAIController>(GetController());
		controller->StopBehavior();
	}
}

void ABaseZombie::Damage(float damage)
{
	m_CurrentHealth -= damage;
}

float ABaseZombie::GetWalkSpeed() const
{
	return m_WalkSpeed;
}

void ABaseZombie::HasSeenPlayer(bool hasSeenPlayer)
{
	m_CanSeePlayer = hasSeenPlayer;
}

bool ABaseZombie::GetCanSeenPlayer() const
{
	return m_CanSeePlayer;
}


