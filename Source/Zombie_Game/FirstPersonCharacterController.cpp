// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacterController.h"
#include "FirstPersonCharacter.h"
#include "Weapons/BasicGun.h"


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
	Super::SetupInputComponent();

	InputComponent->BindAxis("VerticalMove", this, &AFirstPersonCharacterController::VerticalMovement);
	InputComponent->BindAxis("HorizontalMove", this, &AFirstPersonCharacterController::HorizontalMovement);
	InputComponent->BindAxis("LookUpDown", this, &AFirstPersonCharacterController::LookUpDown);
	InputComponent->BindAxis("LookLeftRight", this, &AFirstPersonCharacterController::LookLeftRight);

	InputComponent->BindAction("Shoot", IE_Pressed, this,&AFirstPersonCharacterController::ShootGun);
	InputComponent->BindAction("Reload", IE_Pressed, this, &AFirstPersonCharacterController::Reload);
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

void AFirstPersonCharacterController::LookUpDown(float axisValue)
{
	if (m_pCharacter)
		m_pCharacter->MoveCameraUpDown(axisValue);
}

void AFirstPersonCharacterController::LookLeftRight(float axisValue)
{
	if (m_pCharacter)
		m_pCharacter->MoveCameraLeftRight(axisValue);
}

void AFirstPersonCharacterController::ShootGun()
{
	if (m_pCharacter)
		m_pCharacter->GetEquipedGun().Fire();
		
}

void AFirstPersonCharacterController::Reload()
{
	if (m_pCharacter)
		m_pCharacter->GetEquipedGun().Reload();
}
