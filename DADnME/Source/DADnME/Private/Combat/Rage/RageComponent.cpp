// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/Rage/RageComponent.h"
#include "Player/DnMPlayerController.h"
#include "Player/PlayerCharacter.h"

// Sets default values for this component's properties
URageComponent::URageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URageComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DecayRage(DeltaTime);
}

void URageComponent::AddRage()
{
	CurrentRage = FMath::Clamp(CurrentRage + RageOnHit, 0.f, MaxRage);
	NotifyHUD();
}

void URageComponent::OnDamaged()
{
	CurrentRage = FMath::Clamp(CurrentRage - RageOnDamaged, 0.f, MaxRage);
	NotifyHUD();
}

void URageComponent::DecayRage(float DeltaTime)
{
	if (CurrentRage <= 0.f) return;
	CurrentRage = FMath::Clamp(CurrentRage - RageDecayRate * DeltaTime, 0.f, MaxRage);
	NotifyHUD();
}

void URageComponent::NotifyHUD()
{
	// PlayerController에 업데이트 요청
	APlayerCharacter* Owner = Cast<APlayerCharacter>(GetOwner());
	if (!Owner) return;

	ADnMPlayerController* PC = Cast<ADnMPlayerController>(Owner->GetController());
	if (PC) PC->UpdateMeHUD(
		Owner->GetCurrentHPPercent(),
		GetRagePercent()
	);
}

