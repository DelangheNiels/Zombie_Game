// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "FirstPersonCharacter.generated.h"

/**
 * 
 */

class AFirstPersonCharacterController;

UCLASS()
class ZOMBIE_GAME_API AFirstPersonCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	AFirstPersonCharacter();

protected:
	
	virtual void BeginPlay() override;

	virtual void TookDamage(float damage) override;

public:
	
	virtual void Tick(float DeltaTime) override;

	void HorizontalMovement(float axisValue);
	void VerticalMovement(float axisValue);
	void MoveCameraUpDown(float axisValue);
	void MoveCameraLeftRight(float axisValue);

	UFUNCTION(BlueprintCallable)
		bool GetIsReloading() const;

	void SetIsReloading(bool isReloading);

	UFUNCTION(BlueprintCallable)
		float GetIntensity() const;

	void AddIntensity(float intensity);

	class ABasicGun& GetEquipedGun() const;

	class UCameraComponent& GetCamera() const;

	void ResetIntensity();

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

	UPROPERTY()
	AFirstPersonCharacterController* m_pController;

	float m_Intensity;
};
