// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/SLMainMenuWidget.h"

#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/NameComponent.h"
#include "Game/SLGameInstance.h"
#include "GameFramework/PlayerState.h"

void USLMainMenuWidget::OnConstruct_Implementation()
{
    Super::OnConstruct_Implementation();

    Name->OnTextCommitted.AddDynamic(this, &USLMainMenuWidget::HandleOnEditableTextBoxCommittedEvent);
    Enter->OnPressed.AddDynamic(this, &USLMainMenuWidget::SetPlayerName);
}

void USLMainMenuWidget::SetPlayerName_Implementation()
{
    UNameComponent* NameComponent = GetOwningPlayerState()->FindComponentByClass<UNameComponent>();

    // Update Player State's Name Component
    if(NameComponent)
    {
        NameComponent->Server_SetName(FName(*Name->GetText().ToString()));

        USLGameInstance* SLGameInstance = Cast<USLGameInstance>(GetGameInstance());

        if(!SLGameInstance)
        {
            return;
        }

        SLGameInstance->SetCharacter(GetOwningPlayer());
    }
}

void USLMainMenuWidget::HandleOnEditableTextBoxCommittedEvent_Implementation(const FText& Text,
    ETextCommit::Type CommitMethod)
{
    SetPlayerName();
}