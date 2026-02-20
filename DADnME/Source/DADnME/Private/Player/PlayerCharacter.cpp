// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Player/DnMPlayerController.h"
#include "Player/PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	//PlayerMoveState = EMoveState::Stop;

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	SpringArm->bUsePawnControlRotation = false;
	SpringArm->TargetArmLength = TargetArmLength;
	SpringArm->SetWorldLocationAndRotation(SpringArmLocation, SpringArmRotation);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (ADnMPlayerController* PC = Cast<ADnMPlayerController >(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC_Player, 0);
		}
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GEngine->AddOnScreenDebugMessage(
	//	-1,                    // Key
	//	1.f,                   // Time
	//	FColor::Magenta,       // Color
	//	FString::Printf(TEXT("CurrentTime : %.3f"), CurrentTime),
	//	true,                  // bNewerOnTop
	//	FVector2D(5.f, 5.f)   
	//);
	// 		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, TEXT("if"), true, FVector2D(5.f, 5.f));

	// 
	//if(PlayerMoveState == EMoveState::Sprint)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, TEXT("Sprint"), true, FVector2D(5.f, 5.f));

	//}
	//else if (PlayerMoveState == EMoveState::Move)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, TEXT("move"), true, FVector2D(5.f, 5.f));
	//}
	//else
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("stop"), true, FVector2D(5.f, 5.f));
	//}

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// 키를 입력한 순간에 호출
		EIC->BindAction(IA_Move, ETriggerEvent::Started, this, &APlayerCharacter::StartedMove);
		// 키를 누르고 있는 동안 Tick처럼 호출됨
		EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayerCharacter::TriggeredMove);
		// IA_Move와 관련된 모든 키에서 손을 뗐을 때 호출됨(다른 방향을 왔다 갔다가 눌러도 호출되지 않는다.)
		EIC->BindAction(IA_Move, ETriggerEvent::Completed, this, &APlayerCharacter::CompletedMove);
	}
}

void APlayerCharacter::StartedMove(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();

	float CurrentTime = GetWorld()->GetTimeSeconds();

	if (FMath::IsNearlyZero(FirstMoveTime))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, TEXT("fill FirstMoveTime"), true, FVector2D(5.f, 5.f));
		FirstMoveTime = CurrentTime;
		PrevDir = Input;
	}
	else if (FMath::IsNearlyZero(SecondMoveTime))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, TEXT("fill SecondMoveTime"), true, FVector2D(5.f, 5.f));
		SecondMoveTime = CurrentTime;
		LastDir = Input;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("APlayerCharacter::StartedMove 예외 발생"));
	}

	//// Stop 상태에서 처음 Move키를 눌렀을 때
	//if (PlayerMoveState == EMoveState::Stop && FMath::IsNearlyZero(MoveStartTime))
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, TEXT("if"), true, FVector2D(5.f, 5.f));

	//	PlayerMoveState = EMoveState::Move;
	//	MoveStartTime = CurrentTime;
	//	LastDir = Input;
	//}
	//// Stop 상태이지만 Move키를 같은 방향으로 한번 더 눌렀을 때
	//else if (PlayerMoveState == EMoveState::Stop && Input == LastDir)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, TEXT("same direction"), true, FVector2D(5.f, 5.f));
	//	// DoubleTapThreshold 내에 Move키를 한번 더 눌렀다면, 달리기 상태로 전환
	//	if (CurrentTime - MoveStartTime <= DoubleTapThreshold)
	//	{
	//		PlayerMoveState = EMoveState::Sprint;
	//		MoveStartTime = 0.0f;
	//	}
	//}
	//// Move키를 다른 방향으로 눌렀을 때
	//else if(PlayerMoveState == EMoveState::Stop && Input != LastDir)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, TEXT("other dir"), true, FVector2D(5.f, 5.f));
	//	PlayerMoveState = EMoveState::Move;
	//	MoveStartTime = 0.0f;
	//	LastDir = Input;
	//}

}

void APlayerCharacter::TriggeredMove(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();

	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// 첫 입력과 두 번째 입력의 방향이 같고 DoubleTapThreshold 안에 두 번 누른 경우
		if (PrevDir == LastDir && SecondMoveTime - FirstMoveTime <= DoubleTapThreshold)
		{
			GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;

			// 만약 달리는 중이라면 카메라 효과
			float DeltaTime = GetWorld()->GetDeltaSeconds();
			SprintCameraShake(DeltaTime);
		}
		// 방향이 다르거나 두 번 누른 시간이 늦은 경우
		else
		{
			GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
		}

		//if (PlayerMoveState == EMoveState::Move)
		//{
		//	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
		//}
		//else if (PlayerMoveState == EMoveState::Sprint)
		//{	
		//	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;

		//	// 만약 달리는 중이라면 카메라 효과
		//	float DeltaTime = GetWorld()->GetDeltaSeconds();
		//	SprintCameraShake(DeltaTime);
		//}

		AddMovementInput(Forward, Input.Y);
		AddMovementInput(Right, Input.X);
	}
}

void APlayerCharacter::CompletedMove()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Cyan, TEXT("CompletedMove"));

	// 버튼을 떼는 순간 값이 둘 다 들어있다면
	if (!FMath::IsNearlyZero(FirstMoveTime) && !FMath::IsNearlyZero(SecondMoveTime))
	{
		// 두 번째 입력을 첫 번째 입력으로 인식하도록 값을 옮김, 이후 두 번째 입력을 또 받아 스프린트할지 말지 결정
		FirstMoveTime = SecondMoveTime;
		SecondMoveTime = 0.0f;

		PrevDir = LastDir;
		LastDir = FVector2D::ZeroVector;

		ResetCameraSetting();
	}

	//if (PlayerMoveState == EMoveState::Sprint)
	//{
	//	MoveStartTime = 0.0f;
	//	LastDir = FVector2D::ZeroVector;

	//	//float DeltaTime = GetWorld()->GetDeltaSeconds();
	//	ResetCameraSetting();
	//}

	//PlayerMoveState = EMoveState::Stop;
}

void APlayerCharacter::SprintCameraShake(const float DeltaTime)
{
	// FOV
	float TargetFOV = 100.f;
	Camera->SetFieldOfView(
		FMath::FInterpTo(Camera->FieldOfView, TargetFOV, DeltaTime, 8.f)
	);

	// SpringArm 길이
	float TargetArm = 340.f;
	SpringArm->TargetArmLength =
		FMath::FInterpTo(SpringArm->TargetArmLength, TargetArm, DeltaTime, 6.f);

	// 살짝 흔들리는 Offset
	float SpeedAlpha = GetVelocity().Size() / GetCharacterMovement()->MaxWalkSpeed;
	SpringArm->SocketOffset.Z =
		FMath::Sin(GetWorld()->TimeSeconds * 10.f) * 2.f * SpeedAlpha;
}

void APlayerCharacter::ResetCameraSetting()
{
	// FOV
	Camera->SetFieldOfView(FieldOfView);

	// SpringArm 길이
	SpringArm->TargetArmLength = TargetArmLength;

	// 살짝 흔들리는 Offset
	SpringArm->SocketOffset.Z = 0.0f;
}
