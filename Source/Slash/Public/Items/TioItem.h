// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TioItem.generated.h"

UCLASS()
class SLASH_API ATioItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ATioItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Moving")
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, Category = "Moving")
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();
protected:
	virtual void BeginPlay() override;

	float RunningTime = 0.f;
public:	
	virtual void Tick(float DeltaTime) override;

};
