// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "Perception/AIPerceptionTypes.h"

#include "BaseZombieAIController.generated.h"

/**
 * 
 */

class UBlackboardComponent;

UCLASS()
class ZOMBIE_GAME_API ABaseZombieAIController : public AAIController
{
	GENERATED_BODY()

public:

	ABaseZombieAIController(const FObjectInitializer& objectInitializer = FObjectInitializer::Get());

protected:

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		class UBehaviorTreeComponent* m_pBehaviorTreeComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		class UBehaviorTree* m_pBehaviorTree;

	UBlackboardComponent* m_pBlackboardComponent;

	class UAISenseConfig_Sight* m_pSightConfig;

	UFUNCTION()
		void OnPlayerDetected(AActor* actor, FAIStimulus stimulus);

	void SetupPerceptionSystem();

	virtual void OnPossess(APawn* pawn) override;

	virtual void Tick(float deltaTime) override;

public:

	virtual void BeginPlay() override;

	UBlackboardComponent* GetBlackboard() const;

private:

	void SetupSightPerceptionParameters();
	
	UPROPERTY(EditAnywhere, Category = "Sight Perception")
		float m_SightRadius;

	UPROPERTY(EditAnywhere, Category = "Sight Perception")
		float m_LoseSightRadius;

	UPROPERTY(EditAnywhere, Category = "Sight Perception")
		float m_SightAngle;

	UPROPERTY(EditAnywhere, Category = "Sight Perception")
		float m_MaxAge;

	UPROPERTY(EditAnywhere, Category = "Sight Perception")
		float m_SightSuccessRange;
	
};
