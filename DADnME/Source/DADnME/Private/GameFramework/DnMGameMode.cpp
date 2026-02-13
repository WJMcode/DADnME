// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/PlayerCharacter.h"
#include "Player/DnMPlayerController.h"
#include "GameFramework/DnMGameMode.h"

ADnMGameMode::ADnMGameMode()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
	PlayerControllerClass = ADnMPlayerController::StaticClass();
}
