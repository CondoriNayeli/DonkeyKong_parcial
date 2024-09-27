// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroPegajoso.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

AMuroPegajoso::AMuroPegajoso() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroPegajosoAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MuroPegajosoAsset.Succeeded())
	{
		muroMesh->SetStaticMesh(MuroPegajosoAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Grass.M_Ground_Grass'"));
	if (MaterialAsset.Succeeded())
	{
		muroMesh->SetMaterial(0, MaterialAsset.Object);
	}

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Ambient_Dust.P_Ambient_Dust'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}
}
void AMuroPegajoso::BeginPlay()
{
	Super::BeginPlay();
}


void AMuroPegajoso::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

