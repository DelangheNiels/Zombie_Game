// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include "FirstPersonCharacterController.h"

#include "Weapons/BasicGun.h"

#include "Camera/CameraComponent.h"

#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"

#include "Kismet/KismetSystemLibrary.h"

AFirstPersonCharacter::AFirstPersonCharacter()
{
	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_pCamera->AttachTo(RootComponent);

	GetMesh()->AttachTo(m_pCamera);

	m_IsReloading = false;

	//Create Stimulus comp
	m_pStimulusComponent = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Perception Stimulus Source Component"));
	m_pStimulusComponent->RegisterForSense(TSubclassOf<UAISense_Sight>());
	m_pStimulusComponent->RegisterWithPerceptionSystem();

	m_Intensity = 0;
}

void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();

	FVector location = FVector{0,0,0};
	FRotator rotation = GetActorRotation();

	m_pGun = GetWorld()->SpawnActor<ABasicGun>(m_StartGun,location, rotation);
	m_pGun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, FName(TEXT("Palm_R")));
	m_pGun->SetOwningPlayer(this);

	m_pController = Cast<AFirstPersonCharacterController>(GetController());
}

void AFirstPersonCharacter::TookDamage(float damage)
{
	Super::TookDamage(damage);

	if (m_CurrentHealth <= 0)
	{
		if (m_pController)
			UKismetSystemLibrary::QuitGame(GetWorld(), m_pController,EQuitPreference::Quit,true);
	}
}

void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFirstPersonCharacter::HorizontalMovement(float axisValue)
{
	if (axisValue)
		AddMovementInput(GetActorRightVector(), axisValue);
}

void AFirstPersonCharacter::VerticalMovement(float axisValue)
{
	if (axisValue)
		AddMovementInput(GetActorForwardVector(), axisValue);
}

void AFirstPersonCharacter::MoveCameraUpDown(float axisValue)
{
	float clampedValue = FMath::Clamp<float>(axisValue, -m_CameraRotationSpeed, m_CameraRotationSpeed);
	AddControllerPitchInput(clampedValue);
}

void AFirstPersonCharacter::MoveCameraLeftRight(float axisValue)
{
	float clampedValue = FMath::Clamp<float>(axisValue, -m_CameraRotationSpeed, m_CameraRotationSpeed);
	AddControllerYawInput(clampedValue );
}

bool AFirstPersonCharacter::GetIsReloading() const
{
	return m_IsReloading;
}

void AFirstPersonCharacter::SetIsReloading(bool isReloading)
{
	m_IsReloading = isReloading;
}

float AFirstPersonCharacter::GetIntensity() const
{
	return m_Intensity;
}

void AFirstPersonCharacter::AddIntensity(float intensity)
{
	m_Intensity += intensity;
}

ABasicGun& AFirstPersonCharacter::GetEquipedGun() const
{
	return *m_pGun;
}

UCameraComponent& AFirstPersonCharacter::GetCamera() const
{
	return *m_pCamera;
}

void AFirstPersonCharacter::ResetIntensity()
{
	m_Intensity = 0;
}
