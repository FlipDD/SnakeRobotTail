#include "BigSnake.h"
#include "Segment.h"

#include "Engine/World.h"

// Sets default values
ABigSnake::ABigSnake()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	omega = 2 * PI / period;
}

// Called when the game starts or when spawned
void ABigSnake::BeginPlay()
{
	Super::BeginPlay();

	auto World = GetWorld();
	if (!ensure(World != nullptr)) return;

	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	seg = World->SpawnActor<ASegment>(ASegment::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, Params);
	seg->Initialize(0, omega, 0, wij, psi);
	segs.Add(seg);
	for (int i = 1; i < 15; i++)
	{
		seg = World->SpawnActor<ASegment>(ASegment::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, Params);
		seg->Initialize(i, omega, r, wij, psi)
		segs.Add(seg);

	}
}

// Called every frame
void ABigSnake::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	i = 1;
	while (i < segs.Num() - 1) {
		seg = segs[i];
		seg->ant = segs[i - 1];
		seg->pos = segs[i + 1];
		i++;
	}
}

