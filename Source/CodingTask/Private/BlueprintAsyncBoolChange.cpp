// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintAsyncBoolChange.h"

UBlueprintAsyncBoolChange* UBlueprintAsyncBoolChange::WaitForBooleanChange(ATargetActor* Target)
{
    UBlueprintAsyncBoolChange* Node = NewObject<UBlueprintAsyncBoolChange>();
    Node->ObservedTarget = Target;
    return Node;
}

void UBlueprintAsyncBoolChange::Activate()
{
    UE_LOG(LogTemp, Display, TEXT("BlueprintAsyncBoolChange: activate being called"));
    if (IsValid(ObservedTarget))
    {
        ObservedTarget->OnBooleanChanged.AddDynamic(this, &UBlueprintAsyncBoolChange::HandleBooleanChanged);
        UE_LOG(LogTemp, Warning, TEXT("BlueprintAsyncBoolChange: Successfully bound to event dispatcher."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("BlueprintAsyncBoolChange: FAILED to bind. ObservedTarget invalid!"));
        SetReadyToDestroy();
    }
}

void UBlueprintAsyncBoolChange::HandleBooleanChanged(bool NewValue)
{
    if (NewValue)
    {
        UE_LOG(LogTemp, Display, TEXT("BlueprintAsyncBoolChange: Recived new value"));
        OnBooleanTrue.Broadcast(NewValue);
        SetReadyToDestroy();
    }
}

