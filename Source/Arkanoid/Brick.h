// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

class UBoxComponent;

UCLASS()
class ARKANOID_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* SM_Brick;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UBoxComponent* BoxCollision;

	float SpeedModifierOnBounce = 1.01f;
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent*  OverlappedComp, class AActor* OtherActor,
						class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep,
						const FHitResult& SweepResult);
	
	void DestroyBrick();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
