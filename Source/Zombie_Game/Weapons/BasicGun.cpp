// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicGun.h"

ABasicGun::ABasicGun()
{
	PrimaryActorTick.bCanEverTick = true;

	m_CurrentAmountInClip = m_ClipSize;
	m_FireRate = 1 / m_BulltesPerSecond;

	m_pGunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	m_pGunMesh->AttachTo(RootComponent);

	//Place where bullets get spawned from
	m_pMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Gun Muzzle"));
	m_pMuzzle->AttachTo(m_pGunMesh);
}


void ABasicGun::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasicGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

