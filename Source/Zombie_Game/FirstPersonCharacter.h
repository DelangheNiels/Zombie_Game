// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "FirstPersonCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_GAME_API AFirstPersonCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	AFirstPersonCharacter();

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;

	void HorizontalMovement(float axisValue);
	void VerticalMovement(float axisValue);
	void MoveCameraUpDown(float axisValue);
	void MoveCameraLeftRight(float axisValue);

	bool GetIsReloading() const;
	void SetIsReloading(bool isReloading);

	class ABasicGun& GetEquipedGun() const;

	class UCameraComponent& GetCamera() const;

private:

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* m_pCamera;

	UPROPERTY()
		ABasicGun* m_pGun;

	UPROPERTY(EditAnywhere, Category = "Gun Parameters")
		TSubclassOf<ABasicGun> m_StartGun;

	UPROPERTY(EditAnywhere, Category = "Camera Movement")
		float m_CameraRotationSpeed;

	bool m_IsReloading;

	class UAIPerceptionStimuliSourceComponent* m_pStimulusComponent;
};
