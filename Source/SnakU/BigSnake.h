#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BigSnake.generated.h"

UCLASS()
class SNAKU_API ABigSnake : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABigSnake();

	UPROPERTY()
	class ASegment* seg;
	UPROPERTY()
	TArray<class ASegment*> segs;
	int i;

	bool showArrows = true; // Shows force and velocity arrows

	// Establish the arena size, both in physical coordinates (metres)
	// and in canvas pixels
	int width, height; // canvas pixel coordinates
	int widthPhysical = 8;   // arena width in metres
	int heightPhysical = 5;  // arena height in metres
	int scale = 100;         // Number of pixels per metre.

	int time = 0; // Bit of fancy work to print out simple time
	float omega;

	// ================= PARAMETERS TO CHANGE ====================================

	UPROPERTY(EditAnywhere)
	float period = 2.0;
	UPROPERTY(EditAnywhere)
	float r = 30;
	UPROPERTY(EditAnywhere)
	float wij = 5;
	UPROPERTY(EditAnywhere)
	float psi = 20;

	UPROPERTY(EditAnywhere, Category = "Materials")
		UMaterialInterface* SegmentMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
