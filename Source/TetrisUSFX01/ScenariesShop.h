// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenaries.h"
#include "ScenariesShop.generated.h"

UCLASS()
class TETRISUSFX01_API AScenariesShop : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScenariesShop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual AScenaries* MakerScenaries (FString ScenariesSKU) PURE_VIRTUAL(AScenariesShop::MakerScenaries, return nullptr;);

	AScenaries* SortStage (FString Category);
};
