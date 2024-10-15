#include "Monster.h"


void Monster::BeginPlay()
{
	Super::BeginPlay();
	RenderImage.Create({ 1, 1 }, 'M');
	SetActorLocation({ 10, 2 });
}

void Monster::Tick()
{
	Super::Tick();
}

void Monster::CollisionCheck(AActor* TargetActor)
{
	if (GetActorLocation().X == TargetActor->GetActorLocation().X
		&& GetActorLocation().Y == TargetActor->GetActorLocation().Y)
	{
		// TODO: 부수는 애니메이션
		//delete this;
		//delete TargetActor;
	}
}
