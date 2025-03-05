// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Door.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDPERSON_API UDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


private:
	// Initial door yaw and target open yaw
	float InitialYaw;
	float TargetYaw;

	// Timer handle for the door delay
	FTimerHandle DoorTimerHandle;

	// Opens the door after delay
	void OpenDoorNow();

public:
	// Call this function when the gun is picked up
	UFUNCTION(BlueprintCallable, Category = "Door")
	void TriggerExitDoorOpen();

	// How many seconds to wait before opening the door
	UPROPERTY(EditAnywhere, Category = "Door")
	float DoorOpenDelay = 5.f;

	// The yaw offset to add to the door's initial yaw when open (e.g., 90 degrees)
	UPROPERTY(EditAnywhere, Category = "Door")
	float DoorOpenAngleOffset = 90.f;

	// Optionally, an audio component for door sound (set this in the editor)
	UPROPERTY(EditAnywhere, Category = "Audio")
	class UAudioComponent* AudioComponent;

	// UI widget to display "Proceed to Exit" text (set this in the editor)
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UUserWidget> ProceedWidgetClass;
		
};
