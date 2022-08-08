// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Zone.generated.h"

class UBoxComponent;

UCLASS()
class ZOMBIE_GAME_API AZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool GetIsPlayerInZone() const;

	TArray<AActor*> GetSpawners() const;

private:

	float m_WaitTimer;
	float m_WaitTime = 0.5f;

	bool m_IsPlayerInZone;
	bool m_GotSpawners;

	UPROPERTY()
		TArray<AActor*> m_SpawnersInZone;

	UPROPERTY()
		UBoxComponent* m_pCollisionBox;

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
		void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


};
