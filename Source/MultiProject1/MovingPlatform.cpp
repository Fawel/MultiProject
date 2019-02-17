// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Type::Movable);
}

void AMovingPlatform::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (HasAuthority())
	{
		FVector location = GetActorLocation();
		location += FVector(this->Speed * deltaSeconds, 0, 0);
		SetActorLocation(location);
	}
}