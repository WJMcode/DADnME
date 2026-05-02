// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WB_MeHUD.generated.h"

/**
 * 
 */
UCLASS()
class DADNME_API UWB_MeHUD : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    class UImage* FaceImage;

    UPROPERTY(EditDefaultsOnly, Category = "Media")
    class UMediaPlayer* FaceMediaPlayer;

    UPROPERTY(EditDefaultsOnly, Category = "Media")
    class UMediaTexture* FaceMediaTexture;

protected:
    virtual void NativeConstruct() override;
public:

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateHP(float HPPercent);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateRage(float RagePercent);
};
