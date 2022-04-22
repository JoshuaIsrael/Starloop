// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Lever.h"

ALever::ALever()
{
    Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	Base->SetupAttachment(RootComponent);

    Handle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Handle"));
	Handle->SetupAttachment(Base);
}
