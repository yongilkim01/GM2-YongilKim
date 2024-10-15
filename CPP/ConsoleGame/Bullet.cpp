#include "Bullet.h"
#include <BaseSystem/EngineDebug.h>

void Bullet::BeginPlay()
{
	Super::BeginPlay();
	RenderImage.Create({ 1, 1 }, 'I');
}

void Bullet::Tick()
{
	Super::Tick();
	SetActorLocation(GetActorLocation() + FIntPoint::UP);
}

void Bullet::CollisionCheck(AActor* Actor)
{
	if (GetActorLocation().X == Actor->GetActorLocation().X
		&& GetActorLocation().Y == Actor->GetActorLocation().Y)
	{
		// TODO: 부수는 애니메이션
		MSGASSERT("sdsds");
	}
}
