// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"

AFirstPersonCharacter::AFirstPersonCharacter()
{

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
