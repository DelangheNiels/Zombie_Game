// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include "Weapons/BasicGun.h"

#include "Camera/CameraComponent.h"

AFirstPersonCharacter::AFirstPersonCharacter()
{
	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_pCamera->AttachTo(RootComponent);
}

void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();

	FVector location = FVector{0,0,0};
	FRotator rotation = GetActorRotation();

	m_pGun = GetWorld()->SpawnActor<ABasicGun>(m_StartGun,location, rotation);
	m_pGun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, FName(TEXT("Palm_R")));
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
