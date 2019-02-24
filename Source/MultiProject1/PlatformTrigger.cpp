// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTrigger.h"

#include "Components/BoxComponent.h"
#include <MovingPlatform.h>

// Sets default values
APlatformTrigger::APlatformTrigger()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerObject = CreateDefaultSubobject<UBoxComponent>(FName("TriggerObject"));
	if (TriggerObject == nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("No parent for Platform Trigger"));
	}

	RootComponent = TriggerObject;
	TriggerObject->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapBegin);
	TriggerObject->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapEnd);
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformTrigger::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Begin Overlap"));
		if (LinkedPlatforms.Num() > 0)
			for (const auto platform : LinkedPlatforms)
				platform->AddLinkedPlatform();
	}
}

void APlatformTrigger::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("End Overlap"))
			if (LinkedPlatforms.Num() > 0)
				for (const auto platform : LinkedPlatforms)
					platform->RemoveLinkedPlatform();
	}
}

