// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TioPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


void ATioPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(EchoContext);

	if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(EchoContext, 0);
	}
}

void ATioPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATioPlayerController::Move);
}

void ATioPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputActionVector = InputActionValue.Get<FVector2D>();

	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* MyPawn = GetPawn<APawn>())
	{
		MyPawn->AddMovementInput(ForwardVector, InputActionVector.X); // W, S
		MyPawn->AddMovementInput(RightVector, InputActionVector.Y);   // A, D
	}
}


