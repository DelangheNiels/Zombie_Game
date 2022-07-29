// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicBullet.h"

#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABasicBullet::ABasicBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh"));
	m_pStaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	m_pProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Comp"));
	m_pProjectileMovementComp->SetUpdatedComponent(m_pStaticMesh);
	m_pProjectileMovementComp->InitialSpeed = 5000.0f;
	m_pProjectileMovementComp->bShouldBounce = false;
	m_pProjectileMovementComp->Bounciness = 0.0f;
	m_pProjectileMovementComp->ProjectileGravityScale = 0.0f;

}

// Called when the game starts or when spawned
void ABasicBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ABasicBullet::GetDamage() const
{
	return m_Damage;
}

