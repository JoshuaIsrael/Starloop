// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EngineUtils.h"
#include "SLPlayerController.generated.h"

class USLMainMenuWidget;
/**
 * 
 */
UCLASS()
class STARLOOP_API ASLPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ASLPlayerController();

	virtual void BeginPlay() override;

	UFUNCTION(Client, Reliable, BlueprintCallable)
	void Client_StartGame();

	UFUNCTION(BlueprintCallable)
	void StartGame();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_SetCharacter();

	UFUNCTION(BlueprintCallable)
	void SetCharacter();

	UFUNCTION(BlueprintCallable)
	void SetIsPlayMode(bool bValue);

	UPROPERTY(BlueprintReadWrite)
	UUserWidget* MainMenuWidget;

	template<typename T>
    void FindAllActors(UWorld* World, TArray<T*>& Out)
    {
	    for (TActorIterator<T> It(World); It; ++It)
	    {
		    Out.Add(*It);
	    }
    }

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

private:

	bool bIsCharacterSet = false;

};
