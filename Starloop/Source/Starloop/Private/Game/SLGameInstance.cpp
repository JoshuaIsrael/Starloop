// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SLGameInstance.h"

#include "Game/SLPlayerController.h"

void USLGameInstance::SetCharacter(APlayerController* PlayerController)
{
    if(ASLPlayerController* SLPlayerController = Cast<ASLPlayerController>(PlayerController))
    {
        SLPlayerController->Server_SetCharacter();
    }
}
