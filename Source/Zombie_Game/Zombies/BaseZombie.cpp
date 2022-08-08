// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseZombie.h"
#include "BaseZombieAIController.h"

#include "../Bullets/BasicBullet.h"

#include "../FirstPersonCharacter.h"

#include "../AI/DirectorAI.h"

#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

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

	m_pPlayer = Cast<AFirstPersonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	m_pDirectorAI = Cast<ADirectorAI>(UGameplayStatics::GetActorOfClass(GetWorld(), ADirectorAI::StaticClass()));
}

void ABaseZombie::TookDamage(float damage)
{
	Super::TookDamage(damage);

	if (m_CurrentHealth <= 0)
	{
		GetCharacterMovement()->MaxWalkSpeed = 0;
		ABaseZombieAIController* controller = Cast<ABaseZombieAIController>(GetController());
		controller->StopBehavior();
		SetActorEnableCollision(false);

		if (this->GetDistanceTo(m_pPlayer) <= m_CloseByRange)
		{
			m_pPlayer->AddIntensity(m_IntensityWhenKilledFromCloseRange);
		}

		else
		{
			m_pPlayer->AddIntensity(m_IntensityWhenKilledFromFarRange);
		}

		m_pDirectorAI->DecreaseEnemiesAllive();
	}
}

void ABaseZombie::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
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
	//AFirstPersonCharacter* player = Cast<AFirstPersonCharacter>(otherActor);
	if (m_pPlayer == otherActor && m_IsAttacking)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Dealing damage"));
		m_pPlayer->Damage(m_Damage);
		m_pPlayer->AddIntensity(m_IntensityWhenHittingPlayer);
	}
}


