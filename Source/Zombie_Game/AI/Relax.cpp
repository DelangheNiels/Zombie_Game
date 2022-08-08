// Fill out your copyright notice in the Description page of Project Settings.


#include "Relax.h"

#include "../FirstPersonCharacter.h"

Relax::Relax()
	:DirectorAIState()
{
}

Relax::~Relax()
{
}

void Relax::HandleEnemySpawns(float deltaTime)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("In Relax"));
}

void Relax::HandleStateChange(float deltaTime)
{
}
