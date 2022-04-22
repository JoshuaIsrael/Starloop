// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SLUserWidgetBase.h"
#include "SLMainMenuWidget.generated.h"

class UEditableTextBox;
class UButton;

/**
 * 
 */
UCLASS()
class STARLOOP_API USLMainMenuWidget : public USLUserWidgetBase
{
	GENERATED_BODY()

public:

	virtual void OnConstruct_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UEditableTextBox* Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* Enter;

	UFUNCTION(BlueprintCallable)
	void SetPlayerName();

	    UFUNCTION(BlueprintImplementableEvent)
	    void OnSetPlayerName();

protected:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HandleOnEditableTextBoxCommittedEvent(const FText& Text, ETextCommit::Type CommitMethod);
	
};
