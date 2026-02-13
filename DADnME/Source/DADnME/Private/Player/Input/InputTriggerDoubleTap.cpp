// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedPlayerInput.h"
#include "Player/Input/InputTriggerDoubleTap.h"


ETriggerState UInputTriggerDoubleTap::UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime)
{
	const FVector2D CurrentDir = ModifiedValue.Get<FVector2D>();

	if (CurrentDir.IsNearlyZero())
	{
		return ETriggerState::None;
	}

	CurrentDir.GetSafeNormal();

	/*	
		Dot 값	의미
		1.0		완전히 같은 방향
		0.0		수직
		- 1.0	반대 방향
	*/
	float Dot = FVector2D::DotProduct(CurrentDir, LastDirection);

	const float CurrentTime = PlayerInput->GetWorld()->GetTimeSeconds();

	// ex) CurrentTime 5.2초, LastTapTime가 5.0초 = 0.2초, DoubleTapThreshold 값을 넘지 않았다면 더블탭 작동
	if (Dot > 0.9f && CurrentTime - LastTapTime <= DoubleTapThreshold)
	{
		LastTapTime = -1.f;
		return ETriggerState::Triggered;
	}

	LastDirection = CurrentDir;
	LastTapTime = CurrentTime;
	return ETriggerState::None;
}
