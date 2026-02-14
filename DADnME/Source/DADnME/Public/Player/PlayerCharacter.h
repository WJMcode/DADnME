// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class DADNME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()



protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats")
	float SprintSpeed = 3000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats")

	float WalkSpeed = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats")
	float DoubleTapThreshold = 0.3f;	// 더블 탭하여 달리기 임계치, DoubleTapThreshold 안에 더블 탭을 해야 한다

private:
	bool bIsSprinting = false;
	bool bCanSprint = false;
	float LastPressedTime = 0.0f;
	FVector2D LastDir = FVector2D::ZeroVector;

	float LastMoveCalledTime = 0.0;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UInputMappingContext> IMC_Player;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UInputAction> IA_Move;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UInputAction> IA_Run;

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void Move(const FInputActionValue& Value);
	/*void StartRun(const FInputActionValue& Value);
	void StopRun(const FInputActionValue& Value);*/
	void StartRun(const float CurrentTime);
	void StopRun();
	void ReadySprint();

};
