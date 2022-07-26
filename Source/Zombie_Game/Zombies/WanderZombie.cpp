// Fill out your copyright notice in the Description page of Project Settings.


#include "WanderZombie.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "Components/BoxComponent.h"

AWanderZombie::AWanderZombie()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> zombieVisualAsset(TEXT("SkeletalMesh'/Game/Blueprints/Zombies/WanderZombie/Meshes/WanderZombie.WanderZombie'"));

	if (zombieVisualAsset.Succeeded())
		GetMesh()->SetSkeletalMesh(zombieVisualAsset.Object);
	
}

void AWanderZombie::BeginPlay()
{
	Super::BeginPlay();

}

float AWanderZombie::GetRunSpeed() const
{
	return m_RunSpeed;
}

void AWanderZombie::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (m_CurrentHealth >= 0)
	{
		if (m_CanSeePlayer && GetCharacterMovement()->MaxWalkSpeed != m_RunSpeed)
		{
			m_CurrentMovementSpeed = m_RunSpeed;
			GetCharacterMovement()->MaxWalkSpeed = m_CurrentMovementSpeed;
		}

		if (!m_CanSeePlayer && GetCharacterMovement()->MaxWalkSpeed == m_RunSpeed)
		{
			m_CurrentMovementSpeed = m_WalkSpeed;
			GetCharacterMovement()->MaxWalkSpeed = m_CurrentMovementSpeed;
		}
	}

	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 0;
	}

	if (m_IsAttacking)
	{
		GetCharacterMovement()->MaxWalkSpeed = 0;
	}

}
