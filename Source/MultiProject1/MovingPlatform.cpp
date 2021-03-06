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
	GlobalStartLocation = GetActorLocation();
	GlobalEndLocation = GetTransform().TransformFVector4(TargetLocation);
	Distance = (GlobalEndLocation - GlobalStartLocation).Size();

	if (IsLinked && LinkedPlatformsCountToActivate < 1)
		LinkedPlatformsCountToActivate = 1;

}

void AMovingPlatform::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (HasAuthority())
	{
		if (!IsLinked || (IsLinked && currentActivatePlatforms >= LinkedPlatformsCountToActivate))
		{
			FVector location = GetActorLocation();
			float distanceToEndLocation = (location - GlobalStartLocation).Size();

			FVector direction = (GlobalEndLocation - GlobalStartLocation).GetSafeNormal();
			location += direction * this->Speed * deltaSeconds;
			SetActorLocation(location);

			if (distanceToEndLocation > Distance)
			{
				FVector tmpLocation = GlobalStartLocation;
				GlobalStartLocation = GlobalEndLocation;
				GlobalEndLocation = tmpLocation;
				Distance = (GlobalEndLocation - GlobalStartLocation).Size();
			}
		}
	}
}

void AMovingPlatform::AddLinkedPlatform()
{
	currentActivatePlatforms++;
}

void AMovingPlatform::RemoveLinkedPlatform()
{
	if (currentActivatePlatforms > 0)
		currentActivatePlatforms--;
}
