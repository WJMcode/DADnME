// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RageComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DADNME_API URageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Rage")
	float MaxRage = 100.f;

	UPROPERTY(EditAnywhere, Category = "Rage")
	float RageOnHit = 10.f;       // 적 타격 시 증가량

	UPROPERTY(EditAnywhere, Category = "Rage")
	float RageOnDamaged = 30.f;   // 피격 시 감소량

	UPROPERTY(EditAnywhere, Category = "Rage")
	float RageDecayRate = 5.f;    // 초당 감소량 (가만히 있을 때)

private:
	float CurrentRage = 0.f;

public:	
	// Sets default values for this component's properties
	URageComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	float GetRagePercent() const { return CurrentRage / MaxRage; }

	void AddRage();      // 적 타격 시 호출
	void OnDamaged();    // 피격 시 호출
		
private:
	void DecayRage(float DeltaTime);
	void NotifyHUD();
};
