// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SLUserWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class STARLOOP_API USLUserWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic, Category="User Interface", meta=( Keywords="Begin Play" ))
	void StartConstruction();

	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic, Category="User Interface")
	void OnConstruct();

private:

	void IsPlayerStateValid();

	FTimerHandle CacheTimer;
	
};
