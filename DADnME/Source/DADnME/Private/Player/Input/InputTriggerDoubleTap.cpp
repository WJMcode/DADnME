// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedPlayerInput.h"
#include "Player/Input/InputTriggerDoubleTap.h"


//ETriggerState UInputTriggerDoubleTap::UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime)
//{
//    const float CurrentTime = PlayerInput->GetWorld()->GetTimeSeconds();
//
//    const float CurrMagSq = ModifiedValue.GetMagnitudeSq();
//    const float LastMagSq = LastValue.GetMagnitudeSq();
//    const float ActSq = ActuationThreshold * ActuationThreshold;
//
//    // "이번 프레임에 새로 눌렸는가?"
//    const bool bJustPressed = CurrMagSq >= ActSq && LastMagSq < ActSq;
//
//    if (!bJustPressed)
//    {
//        return ETriggerState::None;
//    }
//
//    // 방향 추출
//    FVector2D Dir = ModifiedValue.Get<FVector2D>().GetSafeNormal();
//
//    // 첫 탭
//    if (LastTapTime < 0.f)
//    {
//        LastTapTime = CurrentTime;
//        LastDirection = Dir;
//        return ETriggerState::Ongoing;
//    }
//
//    // 두 번째 탭
//    const float Delta = CurrentTime - LastTapTime;
//    const float Dot = FVector2D::DotProduct(Dir, LastDirection);
//
//    if (Delta <= DoubleTapThreshold && Dot > 0.9f)
//    {
//        LastTapTime = -1.f;
//        return ETriggerState::Triggered;
//    }
//
//    // 실패 → 다시 첫 탭으로
//    LastTapTime = CurrentTime;
//    LastDirection = Dir;
//    return ETriggerState::Ongoing;
//}
