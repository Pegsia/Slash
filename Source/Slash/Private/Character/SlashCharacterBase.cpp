// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SlashCharacterBase.h"

ASlashCharacterBase::ASlashCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

}


void ASlashCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* ASlashCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ASlashCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void ASlashCharacterBase::InitialAbilityActorInfo()
{
}