// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Enemy/EnemyBase.h"
#include "WB_EnemyHPSlot.generated.h"

/**
 * 
 */
UCLASS()
class DADNME_API UWB_EnemyHPSlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UPROPERTY() AEnemyBase* OwnerEnemy;

    // 에디터에서 조정 가능
    UPROPERTY(EditDefaultsOnly)
    float RemoveDelay = 3.f;

    void ResetTimer(); // 같은 적 재타격 시 타이머 리셋

    // 블루프린트에서 구현
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateHP(float HPPercent);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateName(const FString& Name);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateFaceImage(UTexture2D* FaceTexture);

private:
    FTimerHandle RemoveTimerHandle;

    void OnRemoveTimer();
};
