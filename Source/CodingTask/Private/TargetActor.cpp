// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetActor.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ATargetActor::ATargetActor()
{
	bReplicates = true;
	bTracking = false;
}

void ATargetActor::SetTracking_Implementation(bool bNewTracking)
{
	if (bTracking != bNewTracking)
	{
		UE_LOG(LogTemp, Display, TEXT("TargetActor: Broadcasting new bool"));
		bTracking = bNewTracking;
		UE_LOG(LogTemp, Warning, TEXT("SetTracking called: Boolean is now %s"), bTracking ? TEXT("TRUE") : TEXT("FALSE"));
		OnBooleanChanged.Broadcast(bTracking);
	}
}

void ATargetActor::OnRep_bTracking() 
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_bTracking called: Boolean is now %s"), bTracking ? TEXT("TRUE") : TEXT("FALSE"));
	OnBooleanChanged.Broadcast(bTracking);
}

// Replication
void ATargetActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATargetActor, bTracking);
}

// Called when the game starts or when spawned
void ATargetActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATargetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

