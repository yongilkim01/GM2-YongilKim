#include "FightZone.h"
#include <conio.h>
#include "Player.h"

int UFightZone::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();

	while (true)
	{
		// �̸� ����� #include �ִ��� �̷�°� ����.
		_Player.StatusRender();

		std::cout << "0. ü��ȸ��\n";
		std::cout << "1. ��ȭ\n";
		std::cout << "2. �ʺ������� �̵�\n";
		std::cout << "3. �߱޸����� �̵�\n";
		std::cout << "4. ������̵�\n";
		int Select = _getch();

		switch (Select)
		{
		case '0':
			printf_s("0�������ϴ�.");
			_getch();
			break;
		case '1':
			printf_s("1�������ϴ�.");
			_getch();
			break;
		case '2':
		{
			printf_s("2 �������ϴ�.");
			_getch();
			return 2;
			break;
		}
		case '3':
			printf_s("3 �������ϴ�.");
			_getch();
			return 3;
		case '4':
			printf_s("4 �������ϴ�.");
			_getch();
			return 4;
		default:
			break;
		}

	}

	return 0;
}