// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Enemy/EnemyBase.h"
#include "UI/Enemy/WB_EnemyHUD.h"
#include "DnMPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DADNME_API ADnMPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UWB_MeHUD> MeHUDClass;

	UPROPERTY()
	class UWB_MeHUD* MeHUD;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UWB_EnemyHUD> EnemyHUDClass;

	UPROPERTY()
	UWB_EnemyHUD* EnemyHUD;

public:
	void BeginPlay() override;

public:
	void UpdateMeHUD(float HPPercent, float RagePercent);

	void UpdateEnemyHP(AEnemyBase* Enemy, float HPPercent);
	void RemoveEnemyHP(AEnemyBase* Enemy);
};
