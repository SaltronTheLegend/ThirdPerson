// Fill out your copyright notice in the Description page of Project Settings.


#include "Player3rdPersonCharacter.h"

// Sets default values
APlayer3rdPersonCharacter::APlayer3rdPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayer3rdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayer3rdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayer3rdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

