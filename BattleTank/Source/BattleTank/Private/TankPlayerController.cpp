// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) { UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a Tank")); }
	else { UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing %s"), *ControlledTank->GetName()); }
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *HitLocation.ToString());
		//Get world location if linetrace through corsshair
		//if it hits the landsacpe
			//tell controlled tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//set the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);

	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation %s"), *ScreenLocation.ToString());

	//De-project the sceen of the crosshair to a world direction
	//line-trace along that look direction and see what we hit (up to a max range)
	return true;
}
