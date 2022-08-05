// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseZombie.h"
#include "BaseZombieAIController.h"

#include "../Bullets/BasicBullet.h"

#include "../FirstPersonCharacter.h"

#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

ABaseZombie::ABaseZombie()
{
}

void ABaseZombie::BeginPlay()
{
	Super::BeginPlay();

	SetRightHandCollision();

	m_CanSeePlayer = false;
	m_IsAttacking = false;

	m_CurrentMovementSpeed = m_WalkSpeed;
	GetCharacterMovement()->MaxWalkSpeed = m_CurrentMovementSpeed;
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

void ABaseZombie::PlayAttackMontage()
{
	if (!m_IsAttacking)
	{
		GetCharacterMovement()->MaxWalkSpeed = 0;
		m_IsAttacking = true;
		//GetMesh()->PlayAnimation(m_pAttackMontage, false);
	}
	
}

bool ABaseZombie::GetIsAttacking() const
{
	return m_IsAttacking;
}

void ABaseZombie::StopAttacking()
{
	m_IsAttacking = false;
	GetCharacterMovement()->MaxWalkSpeed = m_CurrentMovementSpeed;
}

void ABaseZombie::SetRightHandCollision()
{
	TArray<UBoxComponent*> boxComps;
	GetComponents<UBoxComponent>(boxComps);

	for (size_t i = 0; i < boxComps.Num(); i++)
	{
		if (boxComps[i]->ComponentHasTag("RightHandCollision"))
		{
			m_pRightHandCollision = boxComps[i];
		}
	}

	if (m_pRightHandCollision)
	{
		m_pRightHandCollision->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, "RightHand");
		m_pRightHandCollision->OnComponentBeginOverlap.AddDynamic(this, &ABaseZombie::OnRightHandOverlapBegin);
	}
}

void ABaseZombie::OnRightHandOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	AFirstPersonCharacter* player = Cast<AFirstPersonCharacter>(otherActor);
	if (player && m_IsAttacking)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Dealing damage"));
		player->Damage(m_Damage);
	}
}


