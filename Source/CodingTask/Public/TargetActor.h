// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBooleanChanged, bool, NewTrackingValue);

UCLASS()
class CODINGTASK_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetActor();

	UPROPERTY(ReplicatedUsing = OnRep_bTracking, BlueprintReadWrite, EditAnywhere, Category = "Boolean")
	bool bTracking;

	UFUNCTION()
	void OnRep_bTracking();

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = "Boolean")
	void SetTracking(bool bNewTracking);

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnBooleanChanged OnBooleanChanged;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
