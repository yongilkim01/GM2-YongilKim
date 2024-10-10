#include "FightZone.h"
#include "Monster.h"
#include "Player.h"
#include <conio.h>
#include "Orc.h"
#include "Goblin.h"
#include <BaseSystem/EngineDebug.h>
#include "TextRpgCore.h"
#include "Orc.h"
#include "Goblin.h"

void UFightZone::CreateMonster()
{
	// FightZone������ ������ 1������ ���� 
	// �� �޸� �����Դϴ�.

	// ���� ���ε�
	// �ʿ��� ���� �ʿ��� ��ŭ�� �޸𸮸� �Ҵ��Ѵ�.
	// new ������ �Դϴ�.
	switch (MonsterType)
	{
	case Enums::MONSTERTYPE::GOBLIN:
	{
		// class AMonster* CurMonster;
		AGoblin* Ptr = new AGoblin();
		CurMonster = Ptr;
		break;
	}
	case Enums::MONSTERTYPE::ORC:
		CurMonster = new AOrc();
		break;
	default:
		break;
	}

	// FightZone�� ����� ����� 
	
	// ������� ��ũ������ ��������.
	// ��δ� ��������� �غ���Ѿ� �Ѵ�.
	CurMonster->BeginPlay();
}


UZone* UFightZone::InPlayer()
{
	if (Enums::MONSTERTYPE::NONE == MonsterType)
	{
		MSGASSERT("���� Ÿ���� �������� ���� ������Դϴ�.");
		return nullptr;
	}

	InMsgPrint();
	_getch();

	// ���������� ����Ͷ�� ������ �� �Ȱ��ٰ� �����Ѵ�.
	// ���� �ֵ���. <= �̹���� ���� �����մϴ�.
	// ���� <= Ŭ����
	// <= �̹����� 
	
	// ����Ϳ��� ������ �ο���� ����.
	// ����� ���̵��� ���� N������ ���Ͱ� �����Ҽ� �ִ�.

	// �� ���� �ȵɱ��?
	// �Լ� ���ο�����
	// �ɹ����������� 2������ ���Ͱ� ���ÿ� ��üȭ �Ǵ� ���� ����� �Ѵ�.
	// ��üȭ �Ǵ� 
	
	CreateMonster();
	APlayer& Player = TextRpgCore::GetPlayer();
	AMonster& Monster = *CurMonster;

	// ���⼭ �ο����?
	while (true)
	{
		Player.StatusRender();
		Monster.StatusRender();
		_getch();

		break;
	}

	// ����� �� ������
	// �����ϰ� �����ָ� �˴ϴ�.
	if (nullptr != CurMonster)
	{
		delete CurMonster;
		CurMonster = nullptr;
	}

	// �� ���ο��� � �޸𸮵��� �Ҵ�Ǿ���
	// ������ �ڵ带 �׳� ����ص� �ɰ̴ϴ�.
	// 4�� 15�б��� ������ ���ư��� �ڵ� �Ʒ��ʿ� �־��ּ���.
	
	return this->GetZone(0);
}