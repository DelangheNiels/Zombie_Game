// Fill out your copyright notice in the Description page of Project Settings.


#include "Peak.h"

#include "../FirstPersonCharacter.h"

Peak::Peak()
	:DirectorAIState()
{
}

Peak::~Peak()
{
}

void Peak::HandleEnemySpawns(float deltaTime)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("In Peak"));
}

void Peak::HandleStateChange(float deltaTime)
{
}
