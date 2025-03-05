// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Components/AudioComponent.h"

// Sets default values for this component's properties
UDoor::UDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UDoor::BeginPlay()
{
	Super::BeginPlay();

	// Save the door's initial yaw
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	// Calculate the target yaw (open position)
	TargetYaw = InitialYaw + DoorOpenAngleOffset;
	
}


// This function is called when the player picks up the gun
void UDoor::TriggerExitDoorOpen()
{
	// Set a timer to open the door after DoorOpenDelay seconds
	GetWorld()->GetTimerManager().SetTimer(DoorTimerHandle, this, &UDoor::OpenDoorNow, DoorOpenDelay, false);
}

// This function is called by the timer after DoorOpenDelay seconds
void UDoor::OpenDoorNow()
{
	// For simplicity, instantly open the door by setting its yaw to TargetYaw.
	// You could use a Timeline for a smooth animation if desired.
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = TargetYaw;
	GetOwner()->SetActorRotation(DoorRotation);

	// Optionally play a door-opening sound if the AudioComponent is valid.
	if (AudioComponent)
	{
		AudioComponent->Play();
	}

	// Create and display the "Proceed to Exit" widget on the player's screen.
	if (ProceedWidgetClass)
	{
		// Create the widget.
		UUserWidget* ProceedWidget = CreateWidget<UUserWidget>(GetWorld(), ProceedWidgetClass);
		if (ProceedWidget)
		{
			ProceedWidget->AddToViewport();
		}
	}
}