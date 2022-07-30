// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

