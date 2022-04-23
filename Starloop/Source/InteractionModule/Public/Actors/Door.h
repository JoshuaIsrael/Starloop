// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class INTERACTIONMODULE_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:

	ADoor();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Interaction")
	void Server_MoveDoor(float Alpha);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "Interaction")
	void Multicast_MoveDoor(float Alpha);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void MoveDoor(float Alpha);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ClosedAngle = -90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float OpenedAngle = -170.0f;

};
