#include "CubosDisparo.h"
#include "Projectile.h"

// Sets default values
ACubosDisparo::ACubosDisparo()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> Cubo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));//"StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));//("StaticMesh'/Game/Geometry/Meshes/canon/StaticMeshcanon.StaticMeshcanon'"));//"StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
    CuboMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Cubo"));
    CuboMesh->SetRelativeScale3D(FVector(1.25f, 0.75f, 0.5f));//(0.2f, 0.05f, 0.5f));
    CuboMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));//(0.f, 0.f, 90.f));
    CuboMesh->SetStaticMesh(Cubo.Object);
    SetRootComponent(CuboMesh);

    Fire = FVector(0.f, 90.f, 0.f);
    FireRate = 0.5f;

}

// Called when the game starts or when spawned
void ACubosDisparo::BeginPlay()
{
    Super::BeginPlay();

    // Inicia el temporizador que dispara los proyectiles repetidamente
    GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ACubosDisparo::FireShot, FireRate, true);

}

// Called every frame
void ACubosDisparo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}


//void ACubosDisparo::FireShot()
//{
//    // GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Disparando proyectil"));
//
//    FVector DirectionRight = FVector(0.f, -1.f, 0.f);
//    FVector DirectionLeft = FVector(0.f, 1.f, 0.f);
//
//    const FRotator FireRotationRight = DirectionRight.Rotation();
//    const FRotator FireRotationLeft = DirectionLeft.Rotation();
//    const FVector SpawnLocationRight = GetActorLocation() + FireRotationRight.RotateVector(Fire);    const FVector SpawnLocationLeft = GetActorLocation() + FireRotationLeft.RotateVector(Fire);
//
//    UWorld* const World1 = GetWorld();
//    if (World1 != nullptr)
//    {
//        // Spawnear proyectiles a la derecha e izquierda
//        AProjectile* ProjectileRight = World1->SpawnActor<AProjectile>(SpawnLocationRight, FireRotationRight);
//        AProjectile* ProjectileLeft = World1->SpawnActor<AProjectile>(SpawnLocationLeft, FireRotationLeft);
//
//        // Mensajes para verificar que los proyectiles se crean
//        /*if (ProjectileRight)
//        {
//            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("Proyectil Spawneado a la derecha"));
//        }
//        if (ProjectileLeft)
//        {
//            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("Proyectil Spawneado a la izquierda"));
//        }*/
//    }
//}

void ACubosDisparo::ShotTimer()
{
}


void ACubosDisparo::FireShot()
{
    UWorld* const World1 = GetWorld();
    if (World1 != nullptr)
    {
       
        TArray<FVector> Directions = {
            FVector(0.0f, 1.0f, 0.0f),   // Derecha
            FVector(0.0f, -1.0f, 0.0f),  // Izquierda
            FVector(0.0f, 0.0f, 1.0f),   // Arriba
            FVector(0.0f, 0.0f, -1.0f)   // Abajo
        };

        for (const FVector& Direction : Directions)
        {
            // Crea la rotación basada en la dirección
            FRotator FireRotation = Direction.Rotation();

            // Calcula la posición donde spawnear el proyectil
            FVector SpawnLocation = GetActorLocation() + Direction * 100.0f; // 100.0f es un desplazamiento inicial

            // Spawnea el proyectil en esa dirección
            AProjectile* Projectile = World1->SpawnActor<AProjectile>(SpawnLocation, FireRotation);
        }
    }
}



//void ACubosDisparo::FireShot()
//{
//    // Define el número de direcciones en las que disparar
//    int numShots =8; // Puedes ajustar este valor para más o menos direcciones
//    float angleStep = 360.0f / numShots;
//
//    UWorld* const World1 = GetWorld();
//    if (World1 != nullptr)
//    {
//        for (int i = 0; i < numShots; i++)
//        {
//            // Calcula la dirección de disparo basándose en el ángulo
//            float currentAngle = i * angleStep;
//            FVector Direction = FVector(FMath::Cos(FMath::DegreesToRadians(currentAngle)), FMath::Sin(FMath::DegreesToRadians(currentAngle)), 0.f);
//            FRotator FireRotation = Direction.Rotation();
//
//            // Calcula la posición donde spawnear el proyectil
//            FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(Fire);
//
//            // Spawnea el proyectil en esa dirección
//            AProjectile* Projectile = World1->SpawnActor<AProjectile>(SpawnLocation, FireRotation);
//
//            // Mensaje de depuración 
//            /*if (Projectile)
//            {
//                GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("Proyectil Spawneado en ángulo: %f"), currentAngle));
//            }*/
//        }
//    }
//}
