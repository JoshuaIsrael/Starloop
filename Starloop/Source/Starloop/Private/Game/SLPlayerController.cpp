// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/SLPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Characters/SLCharacter.h"
#include "Components/NameComponent.h"
#include "GameFramework/PlayerState.h"

ASLPlayerController::ASLPlayerController()
{
    
}

void ASLPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Client only!
    if(HasAuthority())
    {
        return;
    }

    MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);

    if(!MainMenuWidget)
    {
        return;
    }

    MainMenuWidget->AddToPlayerScreen();

    SetIsPlayMode(false);
}

void ASLPlayerController::Client_StartGame_Implementation()
{
    StartGame();
}

void ASLPlayerController::StartGame()
{
    if(!MainMenuWidget)
    {
        return;
    }

    MainMenuWidget->RemoveFromParent();

    SetIsPlayMode(true);
}

void ASLPlayerController::Server_SetCharacter_Implementation()
{
    SetCharacter();
}

void ASLPlayerController::SetCharacter()
{
    if(bIsCharacterSet)
    {
        return;
    }

    TArray<APawn*> FoundPawns;

    // TODO Replace with pooling logic
    FindAllActors(GetWorld(), FoundPawns);

    for(APawn* FoundPawn : FoundPawns)
    {
        APlayerController* PlayerController = Cast<APlayerController>(FoundPawn->GetController());

        // If already possessed by a player controller, move on to next iteration
        if(PlayerController)
        {
            continue;
        }

        UNameComponent* PPNameComponent = FoundPawn->FindComponentByClass<UNameComponent>();
        UNameComponent* PSNameComponent = PlayerState->FindComponentByClass<UNameComponent>();

        if(!PPNameComponent || !PSNameComponent)
        {
            return;
        }

        Possess(FoundPawn);

        PPNameComponent->Server_SetName(PSNameComponent->GetName());

        Client_StartGame();

        bIsCharacterSet = true;

        break;
    }
}

void ASLPlayerController::SetIsPlayMode(bool bValue)
{
    bValue ?  SetInputMode(FInputModeGameOnly()) : SetInputMode(FInputModeGameAndUI());

    SetShowMouseCursor(!bValue);
}
