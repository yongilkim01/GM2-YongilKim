#include "Town.h"
#include <conio.h>
#include "Player.h"

// �����ͳ� ���۷����� ������ 8����Ʈ �̱� ������
int UTown::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();

	while (true)
	{
		// �̸� ����� #include �ִ��� �̷�°� ����.
		_Player.StatusRender();

		std::cout << "0. ü��ȸ��\n";
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������̵�\n";
		std::cout << "3. �߱޸����� �̵�\n";
		int Select = _getch();

		switch (Select)
		{
		case '2':
		{
			_Player.SetCurZone(Select - '0');
			// UFightzone FightZone;

			printf_s("2�������ϴ�.");
			_getch();
			return 2;
			break;
		}
		case '0':
		case '1':
		case '3':
			printf_s("���� �ϼ����� ���� ����Դϴ�.");
			_getch();
			return 1;
		default:
			break;
		}

	}
}
