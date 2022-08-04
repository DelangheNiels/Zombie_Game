// Fill out your copyright notice in the Description page of Project Settings.


#include "AKBullet.h"

AAKBullet::AAKBullet()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> bulletVisualAsset(TEXT("StaticMesh'/Game/Blueprints/Bullets/Meshes/Bullet.Bullet'"));

	if (bulletVisualAsset.Succeeded())
	{
		m_pStaticMesh->SetStaticMesh(bulletVisualAsset.Object);
		m_pStaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		m_pStaticMesh->bEditableWhenInherited = true;
	}
}

void AAKBullet::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

void AAKBullet::BeginPlay()
{
	Super::BeginPlay();
}
