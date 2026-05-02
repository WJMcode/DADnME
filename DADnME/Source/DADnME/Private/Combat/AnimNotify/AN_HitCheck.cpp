// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/PlayerCharacter.h"
#include "Combat/Combo/ComboComponent.h"
#include "Combat/AnimNotify/AN_HitCheck.h"

void UAN_HitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    APlayerCharacter* Player = Cast<APlayerCharacter>(MeshComp->GetOwner());
    if (!Player) return;

    UComboComponent* Combo = Player->FindComponentByClass<UComboComponent>();
    if (Combo) Combo->DoHitCheck();
}
