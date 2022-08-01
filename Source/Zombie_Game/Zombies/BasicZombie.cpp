// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicZombie.h"

ABasicZombie::ABasicZombie()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> zombieVisualAsset(TEXT("SkeletalMesh'/Game/Blueprints/Zombies/NormalZombie/Meshes/BasicZombie.BasicZombie'"));

	if (zombieVisualAsset.Succeeded())
		GetMesh()->SetSkeletalMesh(zombieVisualAsset.Object);
}

void ABasicZombie::BeginPlay()
{
	Super::BeginPlay();
}

void ABasicZombie::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}
