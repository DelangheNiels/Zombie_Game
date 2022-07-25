// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacterController.h"
#include "FirstPersonCharacter.h"

AFirstPersonCharacterController::AFirstPersonCharacterController()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AFirstPersonCharacterController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = false;

	m_pCharacter = Cast<AFirstPersonCharacter>(GetPawn());
}

void AFirstPersonCharacterController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

void AFirstPersonCharacterController::SetupInputComponent()
{
	InputComponent->BindAxis("VerticalMove", this, &AFirstPersonCharacterController::VerticalMovement);
	InputComponent->BindAxis("HorizontalMove", this, &AFirstPersonCharacterController::HorizontalMovement);
}

void AFirstPersonCharacterController::HorizontalMovement(float axisValue)
{
	if (m_pCharacter)
		m_pCharacter->HorizontalMovement(axisValue);
}

void AFirstPersonCharacterController::VerticalMovement(float axisValue)
{
	if (m_pCharacter)
		m_pCharacter->VerticalMovement(axisValue);
}