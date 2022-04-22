// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NameTagWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class NAMEMODULE_API UNameTagWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Name")
	UTextBlock* Name;

	UFUNCTION(BlueprintCallable, Category = "Name")
	void SetText(FName NewText);

	    UFUNCTION(BlueprintImplementableEvent, Category = "Name")
	    void OnSetText(FName NewText);
	
};
