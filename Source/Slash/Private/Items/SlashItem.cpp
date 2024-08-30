// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/SlashItem.h"

ASlashItem::ASlashItem()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMeshComponent);
}


void ASlashItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASlashItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	
}

float ASlashItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float ASlashItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}
