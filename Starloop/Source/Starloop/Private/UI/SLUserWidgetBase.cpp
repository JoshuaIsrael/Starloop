// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SLUserWidgetBase.h"

#include "GameFramework/PlayerState.h"

void USLUserWidgetBase::NativeConstruct()
{
    Super::NativeConstruct();

	StartConstruction();
}

void USLUserWidgetBase::StartConstruction_Implementation()
{
	GetWorld()->GetTimerManager().SetTimer(CacheTimer, this, &USLUserWidgetBase::IsPlayerStateValid, 0.05f, true);
}

void USLUserWidgetBase::OnConstruct_Implementation()
{

}

void USLUserWidgetBase::IsPlayerStateValid()
{
    const APlayerState* PlayerState = GetOwningPlayerState();

	if(!IsValid(PlayerState) || !CacheTimer.IsValid())
	{
	    return;
	}

	GetWorld()->GetTimerManager().ClearTimer(CacheTimer);

	OnConstruct();
}
