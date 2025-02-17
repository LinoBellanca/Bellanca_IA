// Fill out your copyright notice in the Description page of Project Settings.


#include "GruntController.h"

void AGruntController::GetActorEyesViewPoint(FVector& OutLocation, FRotator& OutRotation) const
{
	DetermineAISightPerceptionViewPoint(OutLocation, OutRotation);
}