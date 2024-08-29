// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/TioBird.h"

#include "Components/CapsuleComponent.h"

ATioBird::ATioBird()
{
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	Capsule->SetCapsuleRadius(15.f);
	Capsule->SetCapsuleHalfHeight(15.f);
	SetRootComponent(Capsule);

	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>("BirdMesh");
	BirdMesh->SetupAttachment(GetRootComponent());
}

void ATioBird::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATioBird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATioBird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

