// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/NameComponent.h"

#include "Net/UnrealNetwork.h"

UNameComponent::UNameComponent()
{
	SetIsReplicated(true);
}

void UNameComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UNameComponent, Name);
}

void UNameComponent::Server_SetName_Implementation(FName NewName)
{
    SetName(NewName);
}

void UNameComponent::SetName(FName NewName)
{
    Name = NewName;
}