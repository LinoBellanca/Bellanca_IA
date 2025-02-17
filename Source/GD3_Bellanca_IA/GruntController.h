// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GruntController.generated.h"

/**
 * 
 */
UCLASS()
class GD3_BELLANCA_IA_API AGruntController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void GetActorEyesViewPoint(FVector& OutLocation, FRotator& OutRotation) const override;
	UFUNCTION(BlueprintImplementableEvent, Category="GruntController")
	void DetermineAISightPerceptionViewPoint(FVector& OutLocation, FRotator& OutRotation) const;
};
