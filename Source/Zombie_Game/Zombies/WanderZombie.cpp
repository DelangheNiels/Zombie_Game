// Fill out your copyright notice in the Description page of Project Settings.


#include "WanderZombie.h"

AWanderZombie::AWanderZombie()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> zombieVisualAsset(TEXT("SkeletalMesh'/Game/Blueprints/Zombies/WanderZombie/Meshes/WanderZombie.WanderZombie'"));

	if (zombieVisualAsset.Succeeded())
		GetMesh()->SetSkeletalMesh(zombieVisualAsset.Object);
	
}

void AWanderZombie::BeginPlay()
{
	Super::BeginPlay();
}

void AWanderZombie::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}
