// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/InteractableActor.h"
#include "Components/TimelineComponent.h"
#include "Lever.generated.h"

class ADoor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPullLever, float, Alpha);

/**
 * 
 */
UCLASS()
class INTERACTIONMODULE_API ALever : public AInteractableActor
{
	GENERATED_BODY()

public:

	ALever();

	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Interaction")
	void Server_PullLever(float Alpha);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "Interaction")
	void Multicast_PullLever(float Alpha);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void PullLever(float Alpha);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* Base = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* Handle = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn="true"))
	ADoor* Door = nullptr;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnPullLever OnPullLever;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InactiveAngle = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ActiveAngle = -50.0f;

};
