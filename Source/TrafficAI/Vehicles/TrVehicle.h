﻿// Copyright Anupam Sahu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "PIDController/FRpPIDController.h"
#include "TrVehicle.generated.h"

/**
 *
 */
UCLASS()
class TRAFFICAI_API ATrVehicle : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	void SetTargetTransform(const FTransform& TargetTransform);

private:

	UPROPERTY(EditAnywhere, Category = "Throttle PID Controller")
	float ThrottleKp = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Throttle PID Controller")
	float ThrottleKi = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Throttle PID Controller")
	float ThrottleKd = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Steering PID Controller")
	float SteeringKp = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Steering PID Controller")
	float SteeringKi = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Steering PID Controller")
	float SteeringKd = 1.0f;
	
private:

	float LocationError = 0.0f;
	float HeadingError = 0.0f;
	FRpPIDController<float> ThrottleController{0.0f};
	FRpPIDController<float> SteeringController{0.0f};
	
};
