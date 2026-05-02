// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBase.h"
#include "Player/DnMPlayerController.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	CurrentHP = MaxHP;
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AEnemyBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    CurrentHP -= DamageAmount;
    CurrentHP = FMath::Clamp(CurrentHP, 0.f, MaxHP);

    ADnMPlayerController* PC = Cast<ADnMPlayerController>(
        GetWorld()->GetFirstPlayerController()
    );
    // Enemy 자신도 같이 전달
    if (PC) PC->UpdateEnemyHP(this, CurrentHP / MaxHP);

    if (CurrentHP <= 0) Die();
    return DamageAmount;
}

void AEnemyBase::Die()
{
}