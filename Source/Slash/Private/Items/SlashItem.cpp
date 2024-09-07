// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/SlashItem.h"

#include "Slash/SlashLogChannels.h"

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

float ASlashItem::TransformedSin() const
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float ASlashItem::TransformedCos() const
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void ASlashItem::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogSlash, Log, TEXT("%s BeginOverlapped With %s"), *GetNameSafe(this), *GetNameSafe(OtherActor));
}

void ASlashItem::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogSlash, Log, TEXT("%s EndOverlapped With %s"), *GetNameSafe(this), *GetNameSafe(OtherActor));
}
