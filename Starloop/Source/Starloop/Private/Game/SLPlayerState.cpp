// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/SLPlayerState.h"

#include "Components/NameComponent.h"

ASLPlayerState::ASLPlayerState()
{
    Name = CreateDefaultSubobject<UNameComponent>(TEXT("Name"));
}