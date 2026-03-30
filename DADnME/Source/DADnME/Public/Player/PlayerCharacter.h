// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "PlayerCharacter.generated.h"

UENUM(BlueprintType) 
enum class EMoveState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	//Stop UMETA(DisplayName = "Stop"), Idle이랑 같음
	Move UMETA(DisplayName = "Move"),
	Sprint UMETA(DisplayName = "Sprint")
};

UCLASS()
class DADNME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	// 스프링암
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<class USpringArmComponent> SpringArm;

	// 카메라
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<class UCameraComponent> Camera;

	// 움직임 관련
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	EMoveState PlayerMoveState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SprintSpeed = 3000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")

	float WalkSpeed = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float DoubleTapThreshold = 0.3f;	// 더블 탭하여 달리기 임계치, DoubleTapThreshold 안에 더블 탭을 해야 한다

private:
	// Sprint 관련
	FVector2D PrevDir = FVector2D::ZeroVector;
	FVector2D LastDir = FVector2D::ZeroVector;
	//float MoveStartTime = 0.0;
	float FirstMoveTime = 0.0;
	float SecondMoveTime = 0.0;
	float SprintTargetArmLength = 350.0f;
	float SprintFieldOfView = 120.0f;

	// SpringArm, Camera 관련
	FVector SpringArmLocation = FVector(0.0f, 0.0f, 31.0f);
	FRotator SpringArmRotation = FRotator(-22.0f, 0.0f, 0.0f);
	FVector SpringArmTargetOffset = FVector(76.0f, 0.0f, 0.0f);
	// 캐릭터 회전을 부드럽게 하기 위한 변수
	FRotator TargetRotation = FRotator::ZeroRotator;
	float DefaultTargetArmLength = 300.0f;
	float DefaultFieldOfView = 90.0f;
	


public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UInputMappingContext> IMC_Player;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UInputAction> IA_Move;

	// 공격 A
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UInputAction> IA_AttackA;

private:
	// 콤보 관련 컴포넌트
	UPROPERTY(VisibleAnywhere) 
	class UComboComponent* ComboComponent;

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
	void SetPlayerMoveState(const EMoveState MoveState);
	const EMoveState GetPlayerMoveState();

	// 움직임 관련
	void StartedMove(const FInputActionValue& Value);
	void TriggeredMove(const FInputActionValue& Value);
	void CompletedMove();
	void SprintCameraShake(const float DeltaTime);
	void ResetCameraSetting(const float DeltaTime);

	// 공격 관련
	void OnAttackA(const FInputActionValue& Value);
};
