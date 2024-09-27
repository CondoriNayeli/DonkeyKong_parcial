// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKongGameMode.h"
#include "DonkeyKongCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "ComponentPlataforma.h"
#include "Obstaculo.h"
#include "CubosDisparo.h"
#include "MuroLadrillo.h"
#include "Muro.h"
#include "MuroPegajoso.h"
#include "MuroHielo.h"
#include "MuroElectrico.h"

ADonkeyKongGameMode::ADonkeyKongGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}


}

void ADonkeyKongGameMode::BeginPlay()
{
	Super::BeginPlay();
	//tiempo para cubo disparo
	/*float TiempoInicial = FMath::RandRange(2.0f, 3.0f);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_GenerarCubosDisparo, this, &ADonkeyKongGameMode::GenerarCuboDisparo, TiempoInicial, false);*/


	//PLATAFORMA
	/*FTransform SpawnLocationLadrillo;
	SpawnLocationLadrillo.SetLocation(FVector(1206.0f, -1210.0f, 160.0f));
	SpawnLocationLadrillo.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
	ladrillo = GetWorld()->SpawnActor<AMuroLadrillo>(AMuroLadrillo::StaticClass(), SpawnLocationLadrillo);
	
	FTransform SpawnLocationHielo;
	SpawnLocationHielo.SetLocation(FVector(1156.0f, 492.0f, 787.0f));  
	SpawnLocationHielo.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
	hielo = GetWorld()->SpawnActor<AMuroHielo>(AMuroHielo::StaticClass(), SpawnLocationHielo);
	
	FTransform SpawnLocationPegajoso;
	SpawnLocationPegajoso.SetLocation(FVector(1206.0f, -227.0f, 760.0f));
	SpawnLocationPegajoso.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
	pegajoso = GetWorld()->SpawnActor<AMuroPegajoso>(AMuroPegajoso::StaticClass(), SpawnLocationPegajoso);

	FTransform SpawnLocationElectrico;
	SpawnLocationElectrico.SetLocation(FVector(1156.0f, -1200.0f, 720.0f));
	SpawnLocationElectrico.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
	electrico = GetWorld()->SpawnActor<AMuroElectrico>(AMuroElectrico::StaticClass(), SpawnLocationElectrico);*/
	
	FVector SpawnLocation = FVector(1206.0f, -207.0f, 2427.0f); // Ajusta la posición inicial según tu juego
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f); // Rotación inicial

	// Verifica que el mundo esté disponible antes de spawnear
	UWorld* World = GetWorld();
	if (World)
	{
		// Spawnear el actor de disparo
		ACubosDisparo* CubosDisparoActor = World->SpawnActor<ACubosDisparo>(SpawnLocation, SpawnRotation);
		if (CubosDisparoActor)
		{
			// Aquí puedes configurar propiedades adicionales si es necesario
			CubosDisparoActor->SetActorLocation(SpawnLocation);
		}
	}

	////platafoma

	FVector posicionInicial = FVector(1160.0f, -1100.0f, 400.f);
	FRotator rotacionInicial = FRotator(0.0f, 0.0f, 10.0f);
	FTransform SpawnLocationCP;
	float anchoComponentePlataforma = 200.0f;//600
	float incrementoAltoComponentePlataforma = -40.0f;
	float incrementoAltoEntrePisos = 800.0f;//800
	float incrementoInicioPiso = 100.0f;//100

	for (int npp = 0; npp < 5; npp++) {
		rotacionInicial.Roll = rotacionInicial.Roll * -1;
		incrementoInicioPiso = incrementoInicioPiso * -1;
		incrementoAltoComponentePlataforma = incrementoAltoComponentePlataforma * -1;
		SpawnLocationCP.SetRotation(FQuat(rotacionInicial));

		for (int ncp = 0; ncp < 10; ncp++) {
			SpawnLocationCP.SetLocation(FVector(posicionInicial.X, posicionInicial.Y + anchoComponentePlataforma * ncp, posicionInicial.Z));
			componentesPlataforma.Add(GetWorld()->SpawnActor<AComponentPlataforma>(AComponentPlataforma::StaticClass(), SpawnLocationCP));
			if (ncp < 9) {
				posicionInicial.Z = posicionInicial.Z + incrementoAltoComponentePlataforma;
			}
		}

		posicionInicial.Z = posicionInicial.Z + incrementoAltoEntrePisos;
		posicionInicial.Y = posicionInicial.Y + incrementoInicioPiso;
	}

	

	
}
	
void ADonkeyKongGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
//
//void ADonkeyKongGameMode::GenerarCuboDisparo()
//{
//	// Verificar que hay plataformas disponibles
//	if (componentesPlataforma.Num() > 0)
//	{
//		int32 IndicePlataforma = FMath::RandRange(0, componentesPlataforma.Num() - 1);
//		AComponentPlataforma* PlataformaSeleccionada = componentesPlataforma[IndicePlataforma];
//
//		if (PlataformaSeleccionada && !PlataformasConCubos.Contains(PlataformaSeleccionada)) // Ver si la plataforma ya tiene un cubo de disparo
//		{
//			FVector PosicionPlataforma = PlataformaSeleccionada->GetActorLocation();
//			FVector PosicionCubosDisparo = PosicionPlataforma + FVector(0.0f, 0.0f, 150.0f);
//
//			// Crear el cubo de disparo
//			ACubosDisparo* CuboDisparo = GetWorld()->SpawnActor<ACubosDisparo>(ACubosDisparo::StaticClass(), PosicionCubosDisparo, FRotator::ZeroRotator);
//
//			if (CuboDisparo)
//			{
//				CubosDisparoArray.Add(CuboDisparo);
//				PlataformasConCubos.Add(PlataformaSeleccionada);
//
//				//temporizador para eliminar el cubo después de un tiempo
//				FTimerHandle TimerHandle_DesaparecerCubo;
//				GetWorld()->GetTimerManager().SetTimer(TimerHandle_DesaparecerCubo, [this, CuboDisparo, PlataformaSeleccionada]()
//					{
//						CuboDisparo->Destroy();
//						PlataformasConCubos.Remove(PlataformaSeleccionada);
//
//						// Después de destruir, generar otro cubo en otra plataform
//						GenerarCuboDisparo();
//
//					}, FMath::RandRange(3.0f, 6.0f), false);  // Desaparecer después de 3-6 segundos
//			}
//
//			// Tiempo hasta el próximo cubo
//			float TiempoSiguienteCubo = FMath::RandRange(2.0f, 5.0f);
//			GetWorld()->GetTimerManager().SetTimer(TimerHandle_GenerarCubosDisparo, this, &ADonkeyKongGameMode::GenerarCuboDisparo, TiempoSiguienteCubo, false);
//		}
//		else
//		{
//			GenerarCuboDisparo();
//		}
//	}
//}
//
//





