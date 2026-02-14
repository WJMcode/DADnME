// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/DnMPlayerController.h"
#include "Player/PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		EIC->BindAction(IA_Move, ETriggerEvent::Completed, this, &APlayerCharacter::ReadySprint);
		//EIC->BindAction(IA_Run, ETriggerEvent::Triggered, this, &APlayerCharacter::StartRun);
		//EIC->BindAction(IA_Run, ETriggerEvent::Canceled, this, &APlayerCharacter::StopRun);

	}
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();

	if (Controller)
	{
		if (Input == LastDir)
		{
			const float CurrentTime = GetWorld()->GetTimeSeconds();

			if (bCanSprint && CurrentTime - LastMoveCalledTime <= DoubleTapThreshold)
			{
				GEngine->AddOnScreenDebugMessage(3, 1, FColor::Cyan, FString::Printf(TEXT("CurrentTime - LastPressedTime : %f"), CurrentTime - LastPressedTime));

				StartRun(CurrentTime);
			}
			else
			{
				bCanSprint = false;
				StopRun();
			}
		}
		else
		{
			LastDir = Input;
		}

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		float Speed = bIsSprinting ? SprintSpeed : WalkSpeed;

		GetCharacterMovement()->MaxWalkSpeed = Speed;

		AddMovementInput(Forward, Input.Y);
		AddMovementInput(Right, Input.X);
	}
}

void APlayerCharacter::ReadySprint()
{
	const float CurrentTime = GetWorld()->GetTimeSeconds();
	LastMoveCalledTime = CurrentTime;

	bCanSprint = true;

	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Magenta, TEXT("test"), true, FVector2D(10, 10));
}

void APlayerCharacter::StartRun(const float CurrentTime)
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Blue, TEXT("Run"));
	bIsSprinting = true;

	LastMoveCalledTime = CurrentTime;
}
void APlayerCharacter::StopRun()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, TEXT("Stop"));
	bIsSprinting = false;
}

//
//void APlayerCharacter::StartRun(const FInputActionValue& Value)
//{
//	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Blue, TEXT("Run"));
//	bIsSprinting = true;
//}
//
//void APlayerCharacter::StopRun(const FInputActionValue& Value)
//{
//	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, TEXT("Stop"));
//	bIsSprinting = false;
//}
