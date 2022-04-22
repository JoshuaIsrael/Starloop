// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIONMODULE_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UInteractionComponent();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Trace();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Interact")
	void Server_Interact();

	UFUNCTION(BlueprintCallable, Category = "Interact")
	void Interact();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Trace)
	float LineTraceDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Trace)
	bool bShouldDebug;

	UPROPERTY(BlueprintReadOnly, Category = "Interact")
	AActor* ActorToInteract;

private:

	FTimerHandle TraceTimer;

};
