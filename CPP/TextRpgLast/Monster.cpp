#include "Monster.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>

void AMonster::BeginPlay()
{

}

void AMonster::SetRandomGold(int _Min, int _Max)
{
	if (_Min > _Max)
	{
		MSGASSERT("���� ����� Max�� Min���� �۽��ϴ�.");
	}

	// srand�� ���⼭ �Ұų�?
	int Gold = rand() % (_Max - _Min) + _Min;
	SetGold(Gold);
}