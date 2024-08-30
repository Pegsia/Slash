// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/SlashAttributeSet.h"

#include "Net/UnrealNetwork.h"


/* ---------------------------------------------------------------
	FGameplayAttributeData Corresponding Boiler Plate
-----------------------------------------------------------------*/
void USlashAttributeSet::OnRep_Health(const FGameplayAttributeData& OldData) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Health, OldData);
}

void USlashAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Health, COND_None, REPNOTIFY_Always);
}
