// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/ComboDataAsset.h"
#include "ComboComponent.generated.h"

UENUM()
enum class EComboState : uint8
{
	Idle,           // 아무것도 안 함
	Playing,        // 애니메이션 재생 중, 입력 무시
	WindowOpen,     // 콤보 입력 받는 중
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DADNME_API UComboComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TArray<UComboDataAsset*> ComboSet; // 직접 보유

	UComboDataAsset* CurrentCombo = nullptr;
	EComboState State = EComboState::Idle;

	// 윈도우 열렸을 때 들어온 입력 저장
	TOptional<EAttackInput> BufferedInput;

private:
	/*	타이머를 식별하는 ID 같은 것
		타이머를 나중에 취소하거나 확인할 때
		이 핸들로 어떤 타이머인지 특정함		*/
	FTimerHandle ComboWindowTimerHandle;

public:	
	// Sets default values for this component's properties
	UComboComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void ReceiveInput(const EAttackInput Input);

private:
	void ExecuteCombo(UComboDataAsset* DataAsset);

public:
	UFUNCTION()
	void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);	// AnimNotify에서 호출
	void OnComboWindowClose();
};
