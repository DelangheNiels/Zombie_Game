// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"

#include "Camera/CameraComponent.h"

AFirstPersonCharacter::AFirstPersonCharacter()
{
	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_pCamera->AttachTo(RootComponent);
}

void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFirstPersonCharacter::HorizontalMovement(float axisValue)
{
	if (axisValue)
		AddMovementInput(GetActorRightVector(), axisValue);
}

void AFirstPersonCharacter::VerticalMovement(float axisValue)
{
	if (axisValue)
		AddMovementInput(GetActorForwardVector(), axisValue);
}
