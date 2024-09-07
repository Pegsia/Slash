// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/SlashWeapon.h"

#include "GameFramework/Character.h"
#include "Slash/SlashLogChannels.h"

void ASlashWeapon::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	UE_LOG(LogSlash, Log, TEXT("Weapon BeginOverlapped"));
	if(OtherActor)
	{
		if(ACharacter* Character = Cast<ACharacter>(OtherActor))
		{
			StaticMeshComponent->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, FName("WeaponSocket"));
			StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}		
	}
}

void ASlashWeapon::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	UE_LOG(LogSlash, Log, TEXT("Weapon EndOverlapped"));
}
