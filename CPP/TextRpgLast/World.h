#pragma once
#include "Town.h"
#include "FightZone.h"

// ��� ���� �����ϴ� ������ ����
// ��������
// UZone�� �����ϴ� ������ 
class UWorld
{
public:
	void ZoneInit();

	void PlayerZonePlay();

	UTown Town0;
	UTown Town1;
	UFightZone FZone0;
};

