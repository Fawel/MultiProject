// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Type::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMovingPlatform::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (HasAuthority())
	{
		FVector location = GetActorLocation();
		FVector GLobalTarget = GetTransform().TransformFVector4(TargetLocation);
		FVector direction = (GLobalTarget - location).GetSafeNormal();
		location += direction * this->Speed * deltaSeconds;
		SetActorLocation(location);
	}
}