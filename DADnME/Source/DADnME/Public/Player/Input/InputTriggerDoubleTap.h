// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputTriggers.h"
#include "InputTriggerDoubleTap.generated.h"

/**
 * 플레이어가 더블 탭하여 달리기를 위한 클래스 ,
 * 사용하지 않음, PlayerCharacter에서 해결
 */
UCLASS()
class DADNME_API UInputTriggerDoubleTap : public UInputTrigger
{
	GENERATED_BODY()
	
//public:
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger")
//	float DoubleTapThreshold = 0.3f;	// 더블 탭하여 달리기 임계치, DoubleTapThreshold 안에 더블 탭을 해야 한다
//
//private:
//	bool bWaitingForSecondTap = false;
//	FVector2D LastDirection;
//	float LastTapTime = -1.f;
//
//public:
//	virtual ETriggerState UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime) override;

};
