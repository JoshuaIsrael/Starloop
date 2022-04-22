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

	UFUNCTION(BlueprintCallable, Category = "Name")
	FORCEINLINE FName GetName() const { return Name; }

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Name")
	void Server_SetName(FName NewName);

	UFUNCTION(BlueprintCallable, Category = "Name")
	void SetName(FName NewName);

	    UFUNCTION(BlueprintImplementableEvent, Category = "Name")
	    void OnSetName(FName NewName);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Name")
    void SetNameTag();

protected:

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Name")
	FName Name = FName();

};
