// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Enemy/WB_EnemyHUD.h"
#include "UI/Enemy/WB_EnemyHPSlot.h"
#include "Components/HorizontalBoxSlot.h"

void UWB_EnemyHUD::AddOrUpdateEnemy(AEnemyBase* Enemy, float HPPercent)
{
    for (UWB_EnemyHPSlot* HPSlot : ActiveSlots)
    {
        if (HPSlot->OwnerEnemy == Enemy)
        {
            HPSlot->UpdateHP(HPPercent);
            HPSlot->ResetTimer(); // 재타격 시 타이머 리셋
            return;
        }
    }

    // 새 슬롯 생성
    UWB_EnemyHPSlot* NewSlot = CreateWidget<UWB_EnemyHPSlot>(GetOwningPlayer(), HPSlotClass);
    NewSlot->OwnerEnemy = Enemy;
    NewSlot->UpdateHP(HPPercent);
    NewSlot->UpdateName(Enemy->EnemyName);       // 이름 전달
    NewSlot->UpdateFaceImage(Enemy->FaceImage);  // 이미지 전달
    NewSlot->ResetTimer();

    UHorizontalBoxSlot* BoxSlot =
        Cast<UHorizontalBoxSlot>(HPSlotBox->InsertChildAt(0, NewSlot));
    if (BoxSlot)
    {
        BoxSlot->SetPadding(FMargin(150.f, 0.f, 0.f, 0.f));
    }
    ActiveSlots.Insert(NewSlot, 0);
    if (ActiveSlots.Num() > MaxSlotCount)
    {
        HPSlotBox->RemoveChild(ActiveSlots.Last());
        ActiveSlots.Pop();
    }
}

void UWB_EnemyHUD::RemoveEnemy(AEnemyBase* Enemy)
{
    for (int32 i = 0; i < ActiveSlots.Num(); ++i)
    {
        if (ActiveSlots[i]->OwnerEnemy == Enemy)
        {
            HPSlotBox->RemoveChild(ActiveSlots[i]);
            ActiveSlots.RemoveAt(i);
            return;
        }
    }
}
