// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBindInteractEvents, AActor*, ActorToInteract);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteract, AActor*, ActorToInteract);

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

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "Interact")
	void Multicast_TakeOwnership(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "Interact")
	void TakeOwnership(AActor* Actor);

	UPROPERTY(BlueprintAssignable)
	FOnInteract OnInteract;

	UPROPERTY(BlueprintAssignable)
	FOnBindInteractEvents OnBindInteractionEvents;

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
