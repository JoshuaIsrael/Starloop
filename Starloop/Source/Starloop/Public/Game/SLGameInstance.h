// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SLGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class STARLOOP_API USLGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetCharacter(APlayerController* PlayerController);
	
};
