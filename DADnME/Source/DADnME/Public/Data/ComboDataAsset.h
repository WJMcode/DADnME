// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ComboDataAsset.generated.h"

/**
 * 콤보 목록
 * A
 * AA
 * 
 * S
 * SS
 * 
 * AS 
 * ASA
 * ASA-S
 * 
 * 대쉬-A
 * 대쉬-S
 * 대쉬-S연타
 * 
 * 잡기
 */

// EAttackInput.h
UENUM(BlueprintType)
enum class EAttackInput : uint8
{
    None,
    A,          // 주먹1
    S,          // 주먹2
};

UCLASS()
class DADNME_API UComboDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere) 
    FString AttackName;

    // 이 공격을 발동시키는 단일 입력
    // "이전 공격 후 어떤 키를 눌러야 이 공격이 나오는가"
    UPROPERTY(EditAnywhere) 
    EAttackInput TriggerInput;

    UPROPERTY(EditAnywhere) 
    UAnimMontage* AttackMontage;

    // 노티파이 발생 후 TimingWindow 시간 안에 키를 입력해야 기술이 나갑니다.
    UPROPERTY(EditAnywhere) 
    float TimingWindow = 0.3f;

    // 이 공격 후 연결 가능한 다음 공격들
    UPROPERTY(EditAnywhere) 
    TArray<UComboDataAsset*> NextCombos;
};
