// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicBullet.generated.h"

UCLASS()
class ZOMBIE_GAME_API ABasicBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicBullet();

protected:

	UPROPERTY(EditAnywhere, Category = "Bullet parameters")
		float m_Damage;

	UPROPERTY()
		UStaticMeshComponent* m_pStaticMesh;

	UPROPERTY()
		class UProjectileMovementComponent* m_pProjectileMovementComp;

	float m_TimeToDestroy{};
	float m_DestroyTimer{};

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float GetDamage() const;


};
