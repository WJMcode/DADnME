// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBase.h"
#include "EnemyBoss.generated.h"

/**
 * 
 */
UCLASS()
class DADNME_API AEnemyBoss : public AEnemyBase
{
	GENERATED_BODY()
	
public:
	virtual void Die() override; // 페이즈 전환 처리

	UPROPERTY(EditDefaultsOnly)
	int32 CurrentPhase = 1;
};
