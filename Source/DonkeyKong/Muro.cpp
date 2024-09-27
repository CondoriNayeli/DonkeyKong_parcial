// Fill out your copyright notice in the Description page of Project Settings.



#include "Muro.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

//// Sets default values
AMuro::AMuro()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	muroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMesh"));
	RootComponent = muroMesh;

	SetActorScale3D(FVector(1.0f, 0.25f, 1.0f));

	//MuroCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Pared_collision"));
	//MuroCollision->SetVisibility(true);
	//MuroCollision->SetRelativeScale3D(FVector(2.f, 4.f, 1.60f));
	//MuroCollision->SetCollisionProfileName(TEXT("Triger"));
	//MuroCollision->SetupAttachment(GetRootComponent());

	//MuroCollision->OnComponentBeginOverlap.AddDynamic(this, &AMuro::OnOverlapBegin);

	//InitialLifeSpan = 2.f;
}

//// Called when the game starts or when spawned
void AMuro::BeginPlay()
{
	Super::BeginPlay();
	
}

//// Called every frame
void AMuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AMuro::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor && (OtherActor != this)) {
//		Mensaje();
//	}
//}

//void AMuro::Mensaje()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue,
//		FString::Printf(TEXT("Esta es una pared normal")));
//}