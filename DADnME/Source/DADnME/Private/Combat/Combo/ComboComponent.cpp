// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "Combat/Combo/ComboComponent.h"
#include "Combat/Rage/RageComponent.h"
#include "Player/PlayerCharacter.h"
#include "Enemy/EnemyBase.h"

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

    ACharacter* Owner = Cast<ACharacter>(GetOwner());
    UAnimInstance* AnimInstance = Owner->GetMesh()->GetAnimInstance();

    AnimInstance->OnMontageEnded.AddDynamic(this, &UComboComponent::OnMontageEnded);	
}


// Called every frame
void UComboComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

const EComboState UComboComponent::GetComboState()
{
    return State;
}

void UComboComponent::ReceiveInput(const EAttackInput Input)
{
    switch (State)
    {
    case EComboState::Idle:
        GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
        // 콤보 세트에서 매칭
        for (UComboDataAsset* Combo : ComboSet)
        {
            if (Combo->TriggerInput == Input)
            {
                ExecuteCombo(Combo);
                return;
            }
        }
        break;

    case EComboState::Playing:
        // 재생 중 → 입력 무시
        // 버퍼에 저장하고 싶으면 BufferedInput = Input;
        break;

    case EComboState::WindowOpen:
        // 콤보 윈도우 열림 → 다음 콤보 탐색
        for (UComboDataAsset* Next : CurrentCombo->NextCombos)
        {
            if (Next != nullptr)
            {
                if (Next->TriggerInput == Input)
                {
                    // 타이머 취소 후 다음 콤보 실행
                    GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
                    ExecuteCombo(Next);
                    return;
                }
            }
        }
        break;
    }
}

void UComboComponent::ExecuteCombo(UComboDataAsset* DataAsset)
{
    CurrentCombo = DataAsset;
    State = EComboState::Playing;  // 재생 중으로 변경 → 입력 차단
    BufferedInput.Reset();

    ACharacter* Owner = Cast<ACharacter>(GetOwner());
    Owner->PlayAnimMontage(DataAsset->AttackMontage);
}

void UComboComponent::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{

    // 내 몽타주가 끝난 게 맞는지 확인
    if (Montage != CurrentCombo->AttackMontage) return;

    if (bInterrupted)
    {
        // 피격 등으로 강제 중단됨
        GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
        // 몽타주 완전히 끝남 → Idle로 복귀
        State = EComboState::Idle;
        CurrentCombo = nullptr;
        return;
    }

    // 정상 종료 → 콤보 윈도우 열기
    if (CurrentCombo->NextCombos.Num() > 0)
    {
        // 입력 받기 시작
        State = EComboState::WindowOpen;
        // TimingWindow 안에 다음 입력을 눌러야 함
        GetWorld()->GetTimerManager().SetTimer(         
            ComboWindowTimerHandle,                 // 1. 이 타이머의 핸들 (식별자)
            this,                                   // 2. 함수를 호출할 객체
            &UComboComponent::OnComboWindowClose,   // 3. 시간 후 호출할 함수
            CurrentCombo->TimingWindow,             // 4. 몇 초 후에 호출할지
            false                                   // 5. 반복 여부
        );
    }
    else
    {
        // 다음 콤보 없음 → 바로 Idle
        State = EComboState::Idle;
        CurrentCombo = nullptr;
    }
}

void UComboComponent::OnComboWindowClose()
{
    State = EComboState::Idle;     // 콤보 완전 종료
    CurrentCombo = nullptr;
}

void UComboComponent::DoHitCheck()
{
    if (!CurrentCombo) return;

    ACharacter* Owner = Cast<ACharacter>(GetOwner());
    if (!Owner) return;

    // 캐릭터 앞 방향으로 구체 충돌 체크
    FVector Start = Owner->GetActorLocation();
    FVector End = Start + Owner->GetActorForwardVector() * CurrentCombo->HitRange;

    TArray<FHitResult> HitResults;
    FCollisionShape Sphere = FCollisionShape::MakeSphere(CurrentCombo->HitRadius);

    bool bHit = GetWorld()->SweepMultiByChannel(
        HitResults,
        Start,
        End,
        FQuat::Identity,
        ECC_Pawn,
        Sphere
    );

    if (!bHit) return;

    // 디버그 : 히트 범위 시각화
    DrawDebugSphere(
        GetWorld(),
        End,                    // 위치
        CurrentCombo->HitRadius,// 반지름
        12,                     // 세그먼트
        FColor::Red,            // 색상
        false,                  // 영구 표시 여부
        1.0f                    // 표시 시간
    );

    for (FHitResult& Hit : HitResults)
    {
        AActor* HitActor = Hit.GetActor();

        // 자기 자신 제외
        if (!HitActor || HitActor == Owner) continue;

        // Enemy가 아니면 스킵
        AEnemyBase* HitEnemy = Cast<AEnemyBase>(HitActor);
        if (!HitEnemy) continue;

        // 데미지 전달
        UGameplayStatics::ApplyDamage(
            HitActor,                           // 데미지 받을 액터
            CurrentCombo->Damage,               // 데미지량
            Owner->GetController(),             // 가해자 컨트롤러
            Owner,                              // 가해자 액터
            UDamageType::StaticClass()          // 데미지 타입
        );

        // 적 타격 시 분노 증가
        URageComponent* Rage = Owner->FindComponentByClass<URageComponent>();
        if (Rage) Rage->AddRage();
    }
}



