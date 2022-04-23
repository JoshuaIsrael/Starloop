// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Lever.h"

#include "Actors/Door.h"
#include "Kismet/KismetMathLibrary.h"

ALever::ALever()
{
    bReplicates = true;
    AActor::SetReplicateMovement(true);

    Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	Base->SetupAttachment(RootComponent);

    Handle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Handle"));
	Handle->SetupAttachment(Base);
}

void ALever::BeginPlay()
{
    Super::BeginPlay();

    OnPullLever.AddDynamic(this, &ALever::Server_PullLever);

    Door->SetOwner(this);
}

void ALever::Server_PullLever_Implementation(float Alpha)
{
    Multicast_PullLever(UKismetMathLibrary::Lerp(InactiveAngle, ActiveAngle, Alpha));
    Door->Server_MoveDoor(Alpha);
}

void ALever::Multicast_PullLever_Implementation(float Alpha)
{
    PullLever(Alpha);
}

void ALever::PullLever(float Alpha)
{
    Handle->SetRelativeRotation(FRotator{Alpha, 0.0f, 0.0f});
}
