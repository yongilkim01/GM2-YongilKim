#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"

#include <conio.h>


void UWorld::InPlayer(class UPlayer& _Player)
{
	char InputName[100] = {0,};
	bool IsWrongSelection = false;
	while (true)
	{
		system("cls");

		if (IsWrongSelection)
		{
			printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
			printf_s("a. ����\n");
			printf_s("b. ���Է�\n");
		}
		else {
			std::cout << "�̸��� �����ּ���" << std::endl;
			std::cin >> InputName;
			printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
			printf_s("a. ����\n");
			printf_s("b. ���Է�\n");
		}
		int Select = _getch();
		bool IsEnd = false;
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = true;
			IsWrongSelection = false;
			break;
		case 'b':
		case 'B':
			IsEnd = false;
			IsWrongSelection = false;
			break;
		default:
			IsWrongSelection = true;
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");
			_getch();
			break;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	_Player.SetName(InputName);

	// �������ʱ��� ���⼭ �� ������� ����
	// ������ ������ FightZone�� ��� �ȴ�.
	// ���� ��� �������� 
	
	// new�� �� ����� �ϴ°ų�?
	// 8�Ⱑ
	UTown TownZone;
	TownZone.SetName("�ʺ�����");

	// 10�Ⱑ
	UFightZone FightZone;
	FightZone.SetName("�ʺ������");

	while (true)
	{
		TownZone.InPlayer(_Player);
	}



}