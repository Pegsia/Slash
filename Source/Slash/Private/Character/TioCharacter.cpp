// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TioCharacter.h"

#include "GroomComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ATioCharacter::ATioCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	Hair = CreateDefaultSubobject<UGroomComponent>("Hair");
	Hair->SetupAttachment(GetMesh());
	Hair->AttachmentName = FString("head");

	EyeBrow = CreateDefaultSubobject<UGroomComponent>("EyeBrow");
	EyeBrow->SetupAttachment(GetMesh());
	EyeBrow->AttachmentName = FString("head");
	
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	SpringArmComponent->bUsePawnControlRotation = true;
	
}


void ATioCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATioCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// const FRotator ControlRot= GetControlRotation();
	// const FRotator YawRot = FRotator(0.f, ControlRot.Yaw, 0.f);
	//
	// const FVector ForwardVector = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
	// DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + (ForwardVector * 500.f), FColor::Red, false);
}

void ATioCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
