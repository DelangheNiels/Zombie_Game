// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicGun.generated.h"

class ABasicBullet;

UCLASS()
class ZOMBIE_GAME_API ABasicGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicGun();

	void Fire();
	void Reload();

	int GetCurrentAmmo() const;
	int GetClipSize() const;

	void StopShooting();

protected:
	

	UPROPERTY(EditAnywhere, Category = "Gun Parameters")
		int m_ClipSize;

	int m_CurrentAmmo;

	UPROPERTY(EditAnywhere, Category = "Gun Parameters")
		float m_BulltesPerSecond;

	float m_FireRate;

	UPROPERTY(EditAnywhere, Category = "Gun Parameters")
		float m_ReloadTime;
	float m_ReloadTimer;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* m_pGunMesh;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* m_pMuzzle;

	UPROPERTY(EditAnywhere, Category = "Gun Parameters")
		TSubclassOf<ABasicBullet> m_BulletType;

	UPROPERTY()
		class AFirstPersonCharacter* m_pOwner;

	UPROPERTY()
		UAnimSequence* m_pFireAnimation;

	UPROPERTY()
		UAnimSequence* m_pArmAnimation;

	UPROPERTY()
		UAnimSequence* m_pGunReloadAnimation;

	UPROPERTY()
		UAnimSequence* m_pArmReloadAnimation;

	bool m_IsShooting;


	virtual void BeginPlay() override;

	virtual void ShootGun() PURE_VIRTUAL(ABasicGun::ShootGun, );
	virtual void ReloadGun() PURE_VIRTUAL(ABasicGun::ReloadGun, );

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetOwningPlayer(AFirstPersonCharacter* pCharacter);

};
