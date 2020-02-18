#include "Segment.h"
#include "Components/StaticMeshComponent.h"

#include "UObject/ConstructorHelpers.h"

// Sets default values
ASegment::ASegment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Assets/1M_Cube.1M_Cube"));
	UStaticMesh* Asset = MeshAsset.Object;
	Mesh->SetStaticMesh(Asset);

	Mesh->SetRelativeScale3D(FVector(.5f, .5f, .3f));
}

void ASegment::Initialize(int id_, float omega_, float R_, float w_, float psi_)
{
	id = id_;
	omega = omega_;
	rr = R_ * PI / 180;

	w = w_;
	psi = psi_ * PI / 180;

	v1 = 0;
	v2 = 0;
	phi = 0;
}

// Called when the game starts or when spawned
void ASegment::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASegment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Computation();
}

void ASegment::Computation()
{
	if (ant == nullptr) return;

	float dPhidT;

	// Solver for snake segment
	dPhidT = omega + w * ant->rr*sin(ant->phi - phi - psi) + w * pos->rr*sin(pos->phi - phi + psi);
	phi = phi + dPhidT * dT;

	// Prep to draw the segment
	theta = rr * cos(phi);
	x = ant->x + len * cos(theta);
	y = ant->y + len * sin(theta);

	SetActorLocation(FVector(0, ant->x - 100, ant->y + 250));
	SetActorRotation(FRotator(0, 0, -theta * 50));
}
