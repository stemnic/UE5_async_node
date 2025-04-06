// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TargetActor.h"

#include "BlueprintAsyncBoolChange.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWaitForBooleanChangeOutput, bool, NewValue);

UCLASS()
class CODINGTASK_API UBlueprintAsyncBoolChange : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
    // Blueprint output point
    UPROPERTY(BlueprintAssignable)
    FWaitForBooleanChangeOutput OnBooleanTrue;

    // Create async node
    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Wait for Boolean Change"), Category = "AsyncNode")
    static UBlueprintAsyncBoolChange* WaitForBooleanChange(ATargetActor* Target);

    virtual void Activate() override;

private:
    UPROPERTY()
    ATargetActor* ObservedTarget;

    UFUNCTION()
    void HandleBooleanChanged(bool NewValue);
};
