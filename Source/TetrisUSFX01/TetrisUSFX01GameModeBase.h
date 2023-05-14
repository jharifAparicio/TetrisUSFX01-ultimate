// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Block.h"
#include "Piece.h"
#include "TetrisUSFX01GameModeBase.generated.h"

UCLASS()
class TETRISUSFX01_API ATetrisUSFX01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	ATetrisUSFX01GameModeBase();

	UPROPERTY()
	ABlock* SpawnedActor;
	
	UPROPERTY()
	APiece* SpawnedPiece;

	UFUNCTION()
	void DestroyActorFunction();
private:

	class ATNTPieceBuilder* TNTBuilder;
	class AIcePieceBuilder* IceBuilder;
	class AMetalPieceBuilder* MetalBuilder;
	class AStonePieceBuilder* StoneBuilder;
	class AWoodPieceBuilder* WoodBuilder;

	class AArchitecturalEngineer* Engineer;

	virtual void Tick(float DeltaTime) override;
private:
	float siguientePosicionZ;
};
