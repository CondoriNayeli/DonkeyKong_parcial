// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroElectrico.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

AMuroElectrico::AMuroElectrico()
{

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroElectricoAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MuroElectricoAsset.Succeeded())
	{
		muroMesh->SetStaticMesh(MuroElectricoAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Basic_Floor.M_Basic_Floor'"));
	if (MaterialAsset.Succeeded())
	{
		muroMesh->SetMaterial(0, MaterialAsset.Object);
	}

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}

}
void AMuroElectrico::BeginPlay()
{
	Super::BeginPlay();
}


void AMuroElectrico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//void AMuroElectrico::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor && (OtherActor != this)) {
//		Mensaje();
//	}
//}
//
//void AMuroElectrico::Mensaje()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan,
//		FString::Printf(TEXT("Esta es una pared congelante")));
//}

