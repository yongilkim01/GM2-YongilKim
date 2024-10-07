#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()



void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':
		{
			// Ȯ���� ���δ� 2���� 1
			// 1���� �𿩾� �Ѵ�. �÷��̾��� ��ȭ �ܰ� * 100
			// ���� ���� 5���� �����ϰ� �ִ�. �׷��� 500���� �￩�� �Ѵ�.
			// 1~5������ ���а� ����Ȯ���� ������.
			// �ٿ������ �ʴ´�.
			// 6~10������ �����ϸ� 1�� �ٿ�ȴ�.
			// 10~15�� 0���� �����ϸ� 0���� ��������.
			// 15�� �̻��̸� ��ȭ�� ���ϰ� �ؾ����Ѵ�.

			_Player.SetGold(_Player.GetGold() - GetUsingGold(_Player));

			break;
		}
		case '2':
			return;
		default:
			break;
		}
	}
}

int BlackSmith::GetRandomValue(int Percent)
{
	srand(static_cast<unsigned int>(time(0)));

	// 0�� 1 �� �ϳ��� �������� ����
	return rand() % 2;
}

int BlackSmith::GetUsingGold(UPlayer& _Player)
{
	if (_Player.GetEquipAtt() >= 15) return 0;

	if (GetRandomValue(2) == 0)
	{
		_Player.SetEquipAtt(_Player.GetEquipAtt() + 1);
		return (_Player.GetEquipAtt()) * 100;
	}
	else
	{
		int PrevTriGold = (_Player.GetEquipAtt() + 1) * 100;
		if (6 <= _Player.GetEquipAtt() && _Player.GetEquipAtt() <= 9)
		{
			_Player.SetEquipAtt(_Player.GetEquipAtt() - 1);
		}
		else if (10 <= _Player.GetEquipAtt() && _Player.GetEquipAtt() <= 14)
		{
			_Player.SetEquipAtt(0);
		}
		return PrevTriGold;
	}
}
