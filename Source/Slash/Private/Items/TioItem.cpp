// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/TioItem.h"

ATioItem::ATioItem()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMeshComponent);
}


void ATioItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATioItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	
}

float ATioItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float ATioItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}
