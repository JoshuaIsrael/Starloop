// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SLCharacter.generated.h"

class UInteractionComponent;
class UNameComponent;
class UWidgetComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class STARLOOP_API ASLCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// Sets default values for this character's properties
	ASLCharacter();

	//~ Begin AActor Interface.
	virtual void BeginPlay() override;
	//~ End AActor Interface

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	/** Returns CameraBoom subobject **/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	UFUNCTION(BlueprintCallable, Category = "Interact")
	void Interact();

	    UFUNCTION(BlueprintImplementableEvent, Category = "Interact")
	    void BindInteractionEvents(AActor* Actor);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "Name")
	void SetNameTag();

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* CameraBoom = nullptr;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* FollowCamera = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Name")
	UWidgetComponent* NameTag = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Name")
	UNameComponent* Name = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Name")
	UInteractionComponent* Interaction = nullptr;

private:

	void IsPlayerStateValid();

	FTimerHandle CacheTimer;

};
