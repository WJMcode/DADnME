// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Enemy/EnemyBase.h"
#include "Components/HorizontalBox.h"
#include "WB_EnemyHPSlot.h"
#include "WB_EnemyHUD.generated.h"

/**
 * 
 */
UCLASS()
class DADNME_API UWB_EnemyHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UHorizontalBox* HPSlotBox;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UWB_EnemyHPSlot> HPSlotClass;

    UPROPERTY(EditDefaultsOnly)
    int32 MaxSlotCount = 4;

private:
    UPROPERTY() TArray<UWB_EnemyHPSlot*> ActiveSlots;

public:
    UFUNCTION(BlueprintImplementableEvent)
    void ShowEnemyHUD();
    UFUNCTION(BlueprintImplementableEvent)
    void HideEnemyHUD();

	void AddOrUpdateEnemy(AEnemyBase* Enemy, float HPPercent);
    void RemoveEnemy(AEnemyBase* Enemy);
};
