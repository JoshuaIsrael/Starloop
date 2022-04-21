// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/SLMainMenuWidget.h"

#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/NameComponent.h"
#include "GameFramework/PlayerState.h"

void USLMainMenuWidget::OnConstruct_Implementation()
{
    Super::OnConstruct_Implementation();

    Name->OnTextCommitted.AddDynamic(this, &USLMainMenuWidget::HandleOnEditableTextBoxCommittedEvent);
    Enter->OnPressed.AddDynamic(this, &USLMainMenuWidget::SetPlayerName);
}

void USLMainMenuWidget::SetPlayerName()
{
    if(UNameComponent* NameComponent = GetOwningPlayerState()->FindComponentByClass<UNameComponent>())
    {
        NameComponent->Server_SetName(FName(*Name->GetText().ToString()));

        OnSetPlayerName();
    }
}

void USLMainMenuWidget::HandleOnEditableTextBoxCommittedEvent(const FText& Text, ETextCommit::Type CommitMethod)
{
    SetPlayerName();
}
