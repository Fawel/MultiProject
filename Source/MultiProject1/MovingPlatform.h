// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 *
 */
UCLASS()
class MULTIPROJECT1_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AMovingPlatform();
	virtual void BeginPlay() override;
	virtual void Tick(float deltaSeconds) override;

	UPROPERTY(EditAnywhere)
		bool IsLinked;


	UPROPERTY(EditAnywhere)
		int LinkedPlatformsCountToActivate;

	UPROPERTY(EditAnywhere)
		int Speed;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
		FVector TargetLocation;

	void AddLinkedPlatform();
	void RemoveLinkedPlatform();
private:
	
	int currentActivatePlatforms;

	FVector GlobalStartLocation;
	FVector GlobalEndLocation;
	float Distance;
};
