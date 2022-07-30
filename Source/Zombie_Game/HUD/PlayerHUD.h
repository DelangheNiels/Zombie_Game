// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */

class AFirstPersonCharacter;


UCLASS()
class ZOMBIE_GAME_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	void SetPlayer(AFirstPersonCharacter* pPlayer);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UProgressBar* m_pHealthBar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* m_pCurrentAmmoText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* m_pMaxAmmoText;

protected:
	void NativeTick(const FGeometry& myGeometry, float inDeltaTime) override;

private:

	UPROPERTY()
	AFirstPersonCharacter* m_pPlayer;




	
};
