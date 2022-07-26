// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicGun.h"
#include "../FirstPersonCharacter.h"

#include "Camera/CameraComponent.h"

ABasicGun::ABasicGun()
{
	PrimaryActorTick.bCanEverTick = true;

	m_pGunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	m_pGunMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	//Place where bullets get spawned from
	m_pMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Gun Muzzle"));
	m_pMuzzle->AttachToComponent(m_pGunMesh, FAttachmentTransformRules::KeepRelativeTransform);

	m_ReloadTimer = 0.0f;
	m_IsShooting = false;

}


void ABasicGun::Fire()
{
	m_IsShooting = true;
	ShootGun();
		
}

void ABasicGun::Reload()
{
	ReloadGun();
}

int ABasicGun::GetCurrentAmmo() const
{
	return m_CurrentAmmo;
}

int ABasicGun::GetClipSize() const
{
	return m_ClipSize;
}


void ABasicGun::StopShooting()
{
	m_IsShooting = false;
}

void ABasicGun::BeginPlay()
{
	Super::BeginPlay();
	
	//stays zero in sub classes when placed in constructor
	m_CurrentAmmo = m_ClipSize;
	m_FireRate = 1 / m_BulltesPerSecond;
}

void ABasicGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasicGun::SetOwningPlayer(AFirstPersonCharacter* pCharacter)
{
	m_pOwner = pCharacter;
}

