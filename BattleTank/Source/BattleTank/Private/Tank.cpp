// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Engine/World.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//no need to protect pointers as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetReference(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	TankAimingComponent->SetTurretReference(TurretToSet);

	Barrel = BarrelToSet;
}

void ATank::Fire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Firing"));

	if (!Barrel) { return; }
	//Spawn a projectile @ Barrel socket location

	//FRotator(ProjectileRotation);

	//AProjectile *Projectile = nullptr;

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")), 
		Barrel->GetSocketRotation(FName("Projectile")) 
	);

	Projectile->LaunchProjectile(LaunchSpeed);
}