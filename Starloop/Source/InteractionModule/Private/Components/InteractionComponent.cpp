// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/InteractionComponent.h"

#include "DrawDebugHelpers.h"
#include "Libraries/InteractableInterface.h"

UInteractionComponent::UInteractionComponent()
{
	
}

void UInteractionComponent::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(TraceTimer, this, &UInteractionComponent::Trace, 0.05f, true);
}

void UInteractionComponent::Trace()
{
    FVector Start;
	FVector End;

	FVector PlayerEyesLoc;
	FRotator PlayerEyesRot;

	GetOwner()->GetActorEyesViewPoint(PlayerEyesLoc, PlayerEyesRot);

	Start = PlayerEyesLoc;

	End = PlayerEyesLoc + (PlayerEyesRot.Vector() * LineTraceDistance);
	
	FCollisionQueryParams TraceParams(FName(TEXT("InteractTrace")), true, NULL);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult HitResult = FHitResult(ForceInit);

	bool bIsHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, TraceParams);

	if(bShouldDebug)
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5.f, ECC_WorldStatic, 1.f);
	}

	if (bIsHit)
	{
		ActorToInteract = HitResult.GetActor();
	}
    else
	{
		ActorToInteract = nullptr;
	}
}

void UInteractionComponent::Server_Interact_Implementation()
{
	Interact();
}

void UInteractionComponent::Interact()
{
	if(!ActorToInteract)
	{
	    return;
	}

	Multicast_TakeOwnership(ActorToInteract);

	if(ActorToInteract->GetClass()->ImplementsInterface(UInteractableInterface::StaticClass()))
	{
		OnBindInteractionEvents.Broadcast(ActorToInteract);

		IInteractableInterface::Execute_OnInteract(ActorToInteract);

		OnInteract.Broadcast(ActorToInteract);
	}
}

void UInteractionComponent::Multicast_TakeOwnership_Implementation(AActor* Actor)
{
	TakeOwnership(Actor);
}

void UInteractionComponent::TakeOwnership(AActor* Actor)
{
	Actor->SetOwner(GetOwner());
}
