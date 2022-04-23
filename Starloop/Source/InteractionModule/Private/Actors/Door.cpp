// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Door.h"

#include "Kismet/KismetMathLibrary.h"

ADoor::ADoor()
{
    bReplicates = true;
    AActor::SetReplicateMovement(true);

 	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
    StaticMesh->SetupAttachment(RootComponent);
}

void ADoor::Server_MoveDoor_Implementation(float Alpha)
{
    Multicast_MoveDoor(UKismetMathLibrary::Lerp(ClosedAngle, OpenedAngle, Alpha));
}

void ADoor::Multicast_MoveDoor_Implementation(float Alpha)
{
    MoveDoor(Alpha);
}

void ADoor::MoveDoor(float Alpha)
{
    SetActorRotation(FRotator{0.0f, Alpha, 0.0f});
}