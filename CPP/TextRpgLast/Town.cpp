#include "Town.h"
#include <conio.h>
#include "Player.h"
#include "BlackSmith.h"
#include <iostream>
#include "TextRpgCore.h"
#include <BaseSystem/EngineDebug.h>

UTown::UTown()
	// : BS(*this)
{
	// ���� �̴ϼȶ����� ������ ��ü�Ҽ� �ִ� �Լ��� ������.
	BS.SetParent(this);
}

// �����ͳ� ���۷����� ������ 8����Ʈ �̱� ������
UZone* UTown::InPlayer()
{
	InMsgPrint();

	APlayer& _Player = TextRpgCore::GetPlayer();

	while (true)
	{
		system("cls");
		ZonePrint();
		// �̸� ����� #include �ִ��� �̷�°� ����.
		_Player.StatusRender();

		std::cout << "0. ü��ȸ��\n";
		std::cout << "1. ��ȭ\n";
		std::cout << "2. �ٸ� �������� �̵�\n";

		int Select = _getch();

		switch (Select)
		{
		case '1':
		{
			// �����̽��� ���������� ������ ����������� �ϴ� .
			BS.InPlayer();
			break;
		}
		case '2':
		{
			if (false == IsConnectEmpty())
			{
				UZone* NextZone = ConnectingProgress();
				return NextZone;
			}
			else {
				MSGASSERT("����� ������ �ϳ��� �����ϴ�");
				return nullptr;
			}

			break;
		}
		case '0':
		case '3':
			printf_s("���� �ϼ����� ���� ����Դϴ�.");
			_getch();
			return nullptr;
		default:
			break;
		}

	}
}
