// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/Combo/ComboComponent.h"
#include "Player/PlayerCharacter.h"

// Sets default values for this component's properties
UComboComponent::UComboComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UComboComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UComboComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UComboComponent::ReceiveInput(const EAttackInput Input)
{
	if (Input == EAttackInput::A)
	{
		APlayerCharacter* Owner = Cast<APlayerCharacter>(GetOwner());
		Owner->PlayAnimMontage(RootCombos[0]->AttackMontage);
	}
}

