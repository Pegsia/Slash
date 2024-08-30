// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SlashPlayerState.h"

#include "AbilitySystem/SlashAbilitySystemComponent.h"
#include "AbilitySystem/SlashAttributeSet.h"

ASlashPlayerState::ASlashPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USlashAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<USlashAttributeSet>("AttributeSet");
}

void ASlashPlayerState::BeginPlay()
{
	Super::BeginPlay();
}

UAbilitySystemComponent* ASlashPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ASlashPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
