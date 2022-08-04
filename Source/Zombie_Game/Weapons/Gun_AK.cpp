// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun_AK.h"

#include "../Bullets/BasicBullet.h"

#include "../FirstPersonCharacter.h"

#include "Camera/CameraComponent.h"

#include "Kismet/GameplayStatics.h"

#include "Perception/AISense_Hearing.h"


AGun_AK::AGun_AK()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> gunVisualAsset(TEXT("SkeletalMesh'/Game/Blueprints/Weapons/AK/Meshes/AK_rigged.AK_rigged'"));
	if (gunVisualAsset.Succeeded())
	{
		m_pGunMesh->SetSkeletalMesh(gunVisualAsset.Object);
		m_pGunMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	static ConstructorHelpers::FObjectFinder<UAnimSequence> shootAnim(TEXT("AnimSequence'/Game/Blueprints/Weapons/AK/Animations/AK_Fire_anim_Anim.AK_Fire_anim_Anim'"));
	if (shootAnim.Succeeded())
	{
		m_pFireAnimation = shootAnim.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimSequence> armShootAnim(TEXT("AnimSequence'/Game/Blueprints/Characters/FirstPersonCharacter/Animations/Arms_AK_Fire_anim.Arms_AK_Fire_anim'"));
	if (armShootAnim.Succeeded())
	{
		m_pArmAnimation = armShootAnim.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimSequence> gunReloadAnim(TEXT("AnimSequence'/Game/Blueprints/Weapons/AK/Animations/AK_Reload_anim_Anim.AK_Reload_anim_Anim'"));
	if (gunReloadAnim.Succeeded())
	{
		m_pGunReloadAnimation = gunReloadAnim.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimSequence> armReloadAnim(TEXT("AnimSequence'/Game/Blueprints/Characters/FirstPersonCharacter/Animations/Arms_AK_Reload_anim.Arms_AK_Reload_anim'"));
	if (armReloadAnim.Succeeded())
	{
		m_pArmReloadAnimation = armReloadAnim.Object;
	}

	m_FireTimer = 0;

}


void AGun_AK::BeginPlay()
{
	Super::BeginPlay();
}

void AGun_AK::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (m_pOwner->GetIsReloading())
	{
		m_ReloadTimer += deltaTime;

		if (m_ReloadTimer >= m_ReloadTime)
		{
			m_ReloadTimer = 0;
			m_pOwner->SetIsReloading(false);
			m_CurrentAmmo = m_ClipSize;
		}
	}

	if (m_IsShooting)
	{
		m_FireTimer += deltaTime;
		if (m_FireTimer >= m_FireRate)
		{
			ShootGun();
		}
	}
}

void AGun_AK::ShootGun()
{
	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("%i"), m_ClipSize));

	if (m_CurrentAmmo > 0 && !m_pOwner->GetIsReloading())
	{
		m_FireTimer = 0;
		--m_CurrentAmmo;
		m_pGunMesh->PlayAnimation(m_pFireAnimation, false);
		m_pOwner->GetMesh()->PlayAnimation(m_pArmAnimation, false);

		GetWorld()->SpawnActor<ABasicBullet>(m_BulletType, m_pMuzzle->GetComponentLocation(), m_pOwner->GetCamera().GetComponentRotation());

		UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pFireSound, m_pMuzzle->GetComponentLocation());
		UAISense_Hearing::ReportNoiseEvent(GetWorld(), m_pMuzzle->GetComponentLocation(), 1, this, m_GunShotSoundRange,"Sound");
		
	}

}

void AGun_AK::ReloadGun()
{
	if (m_CurrentAmmo < m_ClipSize && !m_pOwner->GetIsReloading())
	{
		m_pOwner->SetIsReloading(true);

		m_pGunMesh->PlayAnimation(m_pGunReloadAnimation, false);
		m_pOwner->GetMesh()->PlayAnimation(m_pArmReloadAnimation, false);

	}
}
