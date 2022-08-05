// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "IsPlayerInMeleeRange.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_GAME_API UIsPlayerInMeleeRange : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:

	UIsPlayerInMeleeRange();
protected:

public:

	virtual void OnBecomeRelevant(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		float m_MeleeRange = 30.0f;
	
};
