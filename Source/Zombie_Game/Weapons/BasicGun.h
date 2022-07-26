// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicGun.generated.h"

UCLASS()
class ZOMBIE_GAME_API ABasicGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, Category = "Gun Parameters")
		int m_ClipSize;

	int m_CurrentAmountInClip;

	UPROPERTY(EditAnywhere, Category = "Gun Parameters")
		float m_BulltesPerSecond;

	float m_FireRate;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* m_pGunMesh;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* m_pMuzzle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
