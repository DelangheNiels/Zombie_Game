// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicBullet.h"

#include "../Zombies/BaseZombie.h"

#include "GameFramework/ProjectileMovementComponent.h"

#include "Components/SphereComponent.h"

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

	m_TimeToDestroy = 5.0f;
	m_DestroyTimer = 0.0f;

	m_pSphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	m_pSphereCollision->SetCollisionProfileName("Trigger");
	m_pSphereCollision->AttachToComponent(m_pStaticMesh, FAttachmentTransformRules::KeepRelativeTransform);


}

// Called when the game starts or when spawned
void ABasicBullet::BeginPlay()
{
	Super::BeginPlay();
	
	if (m_pSphereCollision)
		m_pSphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ABasicBullet::OnOverlapBegin);
}

// Called every frame
void ABasicBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_DestroyTimer += DeltaTime;
	if (m_DestroyTimer > m_TimeToDestroy)
	{
		Destroy();
	}

}

float ABasicBullet::GetDamage() const
{
	return m_Damage;
}

void ABasicBullet::OnOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (ABaseZombie* zombie = Cast<ABaseZombie>(otherActor))
	{
		zombie->Damage(m_Damage);
		Destroy();
	}

}

