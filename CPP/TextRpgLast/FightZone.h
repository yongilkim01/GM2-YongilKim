#pragma once
#include "Zone.h"
#include "Enums.h"


// ������ ��Ű��ó
class UFightZone : public UZone
{
public:
	void SetMonsterType(Enums::MONSTERTYPE _MonsterType)
	{
		MonsterType = _MonsterType;
	}

	UZone* InPlayer() override;

private:
	// �������� �ٽ��� �ڵ� �����̴�.
	// �������� ����� �������ϴ�.
	// UMonster* Monsters[10];

	//UOrc Monster0;
	//UDragon Monster1;
	//UCobolt Monster2;
	//UCobolt Monster0;

	int MinMonsterCount = 1;
	int MaxMonsterCount = 1;

	// �ɹ������� �������� ���͸� �������� ����.
	//class AOrc Monster;
	//class AGoblin Monster;

	// �θ��������� �̰ɷ� ��� �ִ´�.
	//AOrc Orc;
	//AGoblin Goblin;

	class AMonster* CurMonster;
	// �� FightZone�� ��������� �ϴ� ������ 
	// type���� ������ �ִ�.
	Enums::MONSTERTYPE MonsterType = Enums::MONSTERTYPE::NONE;

	void CreateMonster();
};


