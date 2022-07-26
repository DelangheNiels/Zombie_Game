// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun_AK.h"

AGun_AK::AGun_AK()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> GunVisualAsset(TEXT("SkeletalMesh'/Game/Blueprints/Weapons/AK/Meshes/AK_rigged.AK_rigged'"));

	if (GunVisualAsset.Succeeded())
	{
		m_pGunMesh->SetSkeletalMesh(GunVisualAsset.Object);
		m_pGunMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

void AGun_AK::BeginPlay()
{
	Super::BeginPlay();
}

void AGun_AK::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}
