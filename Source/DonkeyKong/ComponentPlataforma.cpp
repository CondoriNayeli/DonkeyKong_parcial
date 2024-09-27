// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentPlataforma.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
AComponentPlataforma::AComponentPlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("	StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	meshPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	meshPlataforma->SetStaticMesh(MeshAsset.Object);
	RootComponent = meshPlataforma;

	FVector NewScale(1.0f, 2.0f, 0.25f);//(2.0f, 6.0f, 0.5f); // Cambia estos valores según tus necesidades
	SetActorScale3D(NewScale);


		PrimaryActorTick.bCanEverTick = true; // Permitir que esta clase pueda ser actualizada cada frame
		bIsMoving = false; // Inicialmente no se mueve
		MovementSpeed = 2.0f; // Velocidad de movimiento
		MovementAmplitude = 50.0f; // Amplitud del movimi

}

// Called when the game starts or when spawned
void AComponentPlataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComponentPlataforma::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

	if (bIsMoving) {
		// Movimiento horizontal y vertical
		FVector NewLocation = GetActorLocation();

		// Movimiento horizontal
		NewLocation.Y += FMath::Sin(GetWorld()->GetTimeSeconds() * MovementSpeed) * MovementAmplitude;

		// Movimiento vertical
		NewLocation.Z += FMath::Sin(GetWorld()->GetTimeSeconds() * MovementSpeed) * MovementAmplitude;

		// Mover la plataforma
		SetActorLocation(NewLocation);
	}
}

//void AComponentPlataforma::IniciarMovimiento(FVector nuevaPosicionObjetivo)
//{
//	posicionInicial = GetActorLocation();
//	posicionObjetivo = nuevaPosicionObjetivo;
//	moverPlataformaMedio = true;
//	moviendoHaciaObjetivo = true;
//}


