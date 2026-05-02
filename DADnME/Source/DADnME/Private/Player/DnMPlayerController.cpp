// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DnMPlayerController.h"
#include "UI/Me/WB_MeHUD.h"
#include "UI/Enemy/WB_EnemyHUD.h"

void ADnMPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // 플레이어 HUD
    if (MeHUDClass)
    {
        MeHUD = CreateWidget<UWB_MeHUD>(this, MeHUDClass);
        MeHUD->AddToViewport();
    }

    if (EnemyHUDClass)
    {
        EnemyHUD = CreateWidget<UWB_EnemyHUD>(this, EnemyHUDClass);
        EnemyHUD->AddToViewport();
    }
}

void ADnMPlayerController::UpdateMeHUD(float HPPercent, float RagePercent)
{
    if (MeHUD)
    {
        MeHUD->UpdateHP(HPPercent);
        MeHUD->UpdateRage(RagePercent);
    }
}

void ADnMPlayerController::UpdateEnemyHP(AEnemyBase* Enemy, float HPPercent)
{
    if (EnemyHUD)
    {
        EnemyHUD->ShowEnemyHUD();
        EnemyHUD->AddOrUpdateEnemy(Enemy, HPPercent);
    }
}

void ADnMPlayerController::RemoveEnemyHP(AEnemyBase* Enemy)
{
    if (EnemyHUD)
        EnemyHUD->RemoveEnemy(Enemy);
}

