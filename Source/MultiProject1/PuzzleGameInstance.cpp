// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleGameInstance.h"

#include "Engine/Engine.h"
UPuzzleGameInstance::UPuzzleGameInstance(const FObjectInitializer &ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor gameinstance"));

}

void UPuzzleGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Init gameinstance"));
}

void UPuzzleGameInstance::Host()
{
	auto engine = GetEngine();
	if (engine == nullptr) return;

	engine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, FString("Hosting"));

	UWorld* world = GetWorld();
	if (world == nullptr) return;

	world->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzleGameInstance::Join(const FString& address)
{
	auto engine = GetEngine();
	if (engine == nullptr) return;

	engine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, FString("Joining " + address));
}
