// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Me/WB_MeHUD.h"
#include "Components/Image.h"
#include "MediaPlayer.h"
#include "MediaTexture.h"

void UWB_MeHUD::NativeConstruct()
{
    Super::NativeConstruct();

    if (FaceMediaTexture && FaceImage)
    {
        // Media Texture를 Image에 동적으로 할당
        FaceImage->SetBrushResourceObject(FaceMediaTexture);
    }
}
