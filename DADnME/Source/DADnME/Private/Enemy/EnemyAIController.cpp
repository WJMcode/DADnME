// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyAIController.h"
#include "Enemy/EnemyBase.h"

void AEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    if (AEnemyBase* Enemy = Cast<AEnemyBase>(InPawn))
    {
        if (Enemy->BehaviorTree)
            RunBehaviorTree(Enemy->BehaviorTree);
    }
}
