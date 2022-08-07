// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildUp.h"

BuildUp::BuildUp()
{
}

BuildUp::~BuildUp()
{
}

void BuildUp::HandleEnemySpawns()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, TEXT("In build up"));
}
