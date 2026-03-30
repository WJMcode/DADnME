// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BehaviorTree/BTTask_Patrol.h"
#include "Enemy/EnemyAIController.h"
#include "NavigationSystem.h"

UBTTask_Patrol::UBTTask_Patrol()
{
}

EBTNodeResult::Type UBTTask_Patrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();

    FNavLocation RandomPoint;
    UNavigationSystemV1::GetCurrent(Pawn->GetWorld())
        ->GetRandomReachablePointInRadius(Pawn->GetActorLocation(), 500.0f, RandomPoint);

    OwnerComp.GetAIOwner()->MoveToLocation(RandomPoint.Location);
    return EBTNodeResult::Succeeded;
}
