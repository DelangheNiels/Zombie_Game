// Fill out your copyright notice in the Description page of Project Settings.


#include "Peak.h"

Peak::Peak()
{
}

Peak::~Peak()
{
}

void Peak::HandleEnemySpawns()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("In Peak"));
}
