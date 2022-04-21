// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NameComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NAMEMODULE_API UNameComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UNameComponent();

	//~ Begin UObject Interface.
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//~ End UObject Interface.

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FName GetName() const { return Name; }

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_SetName(FName NewName);

	UFUNCTION(BlueprintCallable)
	void SetName(FName NewName);

protected:

	UPROPERTY(Replicated, BlueprintReadOnly)
	FName Name = FName();

};
