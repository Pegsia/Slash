// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SlashCharacter.h"

#include "AbilitySystemComponent.h"
#include "GroomComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/SlashPlayerState.h"

ASlashCharacter::ASlashCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
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

void ASlashCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Server
	InitialAbilityActorInfo();
}

void ASlashCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitialAbilityActorInfo();
}

void ASlashCharacter::InitialAbilityActorInfo()
{
	ASlashPlayerState* SlashPS = Cast<ASlashPlayerState>(GetPlayerState());
	check(SlashPS);

	AbilitySystemComponent = SlashPS->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(SlashPS, this);
	AttributeSet = SlashPS->GetAttributeSet();
}

