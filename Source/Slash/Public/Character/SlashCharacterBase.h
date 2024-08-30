// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "SlashCharacterBase.generated.h"

class UAttributeSet;

UCLASS()
class SLASH_API ASlashCharacterBase : public ACharacter, public  IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASlashCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const;

	
protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
	virtual void InitialAbilityActorInfo();

private:

};
