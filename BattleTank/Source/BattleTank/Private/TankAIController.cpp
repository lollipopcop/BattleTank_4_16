// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//TODO Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);	//TODO check radius is in cm

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//fire if ready
		//ControlledTank->Fire(); //TODO Don't fire every frame
	}
}


