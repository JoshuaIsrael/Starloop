// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SLPlayerState.generated.h"

class UNameComponent;

/**
 * 
 */
UCLASS()
class STARLOOP_API ASLPlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	ASLPlayerState();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UNameComponent* Name = nullptr;
	
};
