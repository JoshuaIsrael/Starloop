// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/InteractableActor.h"
#include "Lever.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTIONMODULE_API ALever : public AInteractableActor
{
	GENERATED_BODY()

public:

	ALever();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* Base = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* Handle = nullptr;
	
};
