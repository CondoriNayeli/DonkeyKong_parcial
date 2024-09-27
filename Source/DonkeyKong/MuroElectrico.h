// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroElectrico.generated.h"
class UParticleSystemComponent;
/**
 * 
 */
UCLASS()
class DONKEYKONG_API AMuroElectrico : public AMuro
{
	GENERATED_BODY()
public:
	AMuroElectrico();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UParticleSystemComponent* ParticleSystem;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
//protected:
//	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
//		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
//
//	void Mensaje() override;

	
};
