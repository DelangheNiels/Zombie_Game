// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "../FirstPersonCharacter.h"
#include "../Weapons/BasicGun.h"

#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

bool UPlayerHUD::Initialize()
{
	bool success = Super::Initialize();
	if (!success)
		return false;

	if(m_pPlayer)
		m_pMaxAmmoText->SetText(FText::FromString(FString::FromInt(m_pPlayer->GetEquipedGun().GetClipSize())));

	return true;
}

void UPlayerHUD::SetPlayer(AFirstPersonCharacter* pPlayer)
{
	m_pPlayer = pPlayer;
}

void UPlayerHUD::NativeTick(const FGeometry& myGeometry, float inDeltaTime)
{

	Super::NativeTick(myGeometry, inDeltaTime);

	if (m_pPlayer)
	{
		m_pHealthBar->SetPercent(m_pPlayer->GetHealthPercentage());
		m_pCurrentAmmoText->SetText(FText::FromString(FString::FromInt(m_pPlayer->GetEquipedGun().GetCurrentAmmo())));

	}
}
