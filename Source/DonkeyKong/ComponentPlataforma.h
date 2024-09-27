// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponentPlataforma.generated.h"

class UStaticMeshComponent;

UCLASS()
class DONKEYKONG_API AComponentPlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComponentPlataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* meshPlataforma;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	bool bIsMoving; // Variable para controlar el movimiento
	float MovementSpeed; // Velocidad del movimiento
	float MovementAmplitude; // Amplitud del movimiento
};
