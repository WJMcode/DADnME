// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBase.h"
#include "EnemySpecial.generated.h"

/**
 * 
 */
UCLASS()
class DADNME_API AEnemySpecial : public AEnemyBase
{
	GENERATED_BODY()

public:
    UFUNCTION()
    virtual void Attack();

    UPROPERTY(EditDefaultsOnly)
    float AttackRange = 200.0f;
};
