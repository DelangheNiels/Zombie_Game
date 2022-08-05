// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	//need to set this here, otherwise death anim starts playing when game starts
	m_CurrentHealth = m_MaxHealth;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	m_CurrentHealth = m_MaxHealth;
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ABaseCharacter::GetCurrentHealth() const
{
	return m_CurrentHealth;
}

float ABaseCharacter::GetMaxHealth() const
{
	return m_MaxHealth;
}

float ABaseCharacter::GetHealthPercentage() const
{
	return m_CurrentHealth / m_MaxHealth;
}

void ABaseCharacter::Damage(float damage)
{
	TookDamage(damage);
}

void ABaseCharacter::TookDamage(float damage)
{
	m_CurrentHealth -= damage;
}

