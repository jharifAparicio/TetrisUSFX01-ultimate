// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Piece.h"
#include "Board.generated.h"

UCLASS()
class TETRISUSFX01_API ABoard : public APawn
{
	GENERATED_BODY()

public:
	//patron singleton
	static ABoard* GetInstance();

protected:
	// Sets default values for this pawn's properties
	ABoard ();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	APiece* CurrentPiece;

	void Rotate();
	void MoveLeft(); 
	void MoveRight();
	void MoveDown();
	void NewPiece();
	void CheckLine();
	void MoveDownToEnd();

	class USoundCue* LineRemoveSoundCue;

	class USoundCue* MoveToEndSoundCue;

	class USoundCue* GameOverSoundCue;

	class USoundCue* GameStartSoundCue;
private:
	enum PieceStatus { PS_NOT_INITED, PS_MOVING, PS_GOT_BOTTOM };
	PieceStatus Status = PS_NOT_INITED;

	const float CoolDown = 0.5f;
	float CoolLeft = 0.5f;
	bool bGameOver = false;

	bool CheckGameOver();

	//patron singleton
	static ABoard *Instance;
};
