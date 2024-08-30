// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlashCharacterBase.h"
#include "SlashCharacter.generated.h"

class UGroomComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SLASH_API ASlashCharacter : public ASlashCharacterBase
{
	GENERATED_BODY()

public:
	ASlashCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
protected:

private:
	virtual void InitialAbilityActorInfo() override;
	
	UPROPERTY(VisibleAnywhere, Category = "Component")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Hair")
	TObjectPtr<UGroomComponent> Hair;

	UPROPERTY(VisibleAnywhere, Category = "Hair")
	TObjectPtr<UGroomComponent> EyeBrow;
};
