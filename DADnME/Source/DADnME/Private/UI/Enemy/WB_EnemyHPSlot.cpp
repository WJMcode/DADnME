// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/DnMPlayerController.h"
#include "UI/Enemy/WB_EnemyHPSlot.h"

void UWB_EnemyHPSlot::ResetTimer()
{
    // 기존 타이머 취소 후 다시 시작
    GetWorld()->GetTimerManager().ClearTimer(RemoveTimerHandle);
    GetWorld()->GetTimerManager().SetTimer(
        RemoveTimerHandle,
        this,
        &UWB_EnemyHPSlot::OnRemoveTimer,
        RemoveDelay,
        false
    );
}

void UWB_EnemyHPSlot::OnRemoveTimer()
{
    // HUD에 자신 제거 요청
    ADnMPlayerController* PC = Cast<ADnMPlayerController>(GetOwningPlayer());
    if (PC) PC->RemoveEnemyHP(OwnerEnemy);
}