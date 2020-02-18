#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Segment.generated.h"

UCLASS()
class SNAKU_API ASegment : public AActor
{
	GENERATED_BODY()

	/** Mesh */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* Mesh;
	
public:	
	// Sets default values for this actor's properties
	ASegment();

	// state variables
	float phi;
	float rr;
	float theta;
	// parameters
	float omega;

	float w;
	float psi;
	// float b = 20;
	 // location
	float x;
	float y;
	// variables
	float a, v1, v2;
	int id;
	float dT = 0.01;
	float len = 50;
	float wid = 5;

	ASegment* ant;
	ASegment* pos;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Initialize(int id_, float omega_, float R_, float w_, float psi_);

	void Computation();
};
