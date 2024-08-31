// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SlashPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"


void ASlashPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(EchoContext);

	if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(EchoContext, 0);
	}
}

void ASlashPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
	EnhancedInputComponent->BindAction(LookUpAction, ETriggerEvent::Triggered, this, &ThisClass::LookUp);
	EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ThisClass::Turn);
}

void ASlashPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	Cast<UEnhancedInputComponent>(InputComponent)->BindAction(JumpAction, ETriggerEvent::Triggered, Cast<ACharacter>(InPawn), &ACharacter::Jump);
}

void ASlashPlayerController::Move(const FInputActionValue& InputActionValue){
	
	const FVector2D InputActionVector = InputActionValue.Get<FVector2D>();

	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* MyPawn = GetPawn<APawn>())
	{
		MyPawn->AddMovementInput(ForwardVector, InputActionVector.Y); // W, S
		MyPawn->AddMovementInput(RightVector, InputActionVector.X);   // A, D
	}
}

void ASlashPlayerController::LookUp(const FInputActionValue& InputActionValue)
{
	if(APawn* MyPawn = GetPawn<APawn>())
	{
		MyPawn->AddControllerPitchInput(InputActionValue.Get<FInputActionValue::Axis1D>()); // Mouse Y
	}
}

void ASlashPlayerController::Turn(const FInputActionValue& InputActionValue)
{
	if(APawn* MyPawn = GetPawn<APawn>())
	{
		MyPawn->AddControllerYawInput(InputActionValue.Get<FInputActionValue::Axis1D>()); // Mouse X
	}
}


