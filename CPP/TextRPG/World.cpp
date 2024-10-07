#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <BaseSystem/EngineFile.h>

// #include "EngineFile.h"

// #include "..\BaseSystem\EngineFile.h"
// �������� ����� �ƴմϴ�.

// #include < <= �����ϴ� �ܺΰ�δ� ũ�� 2���� ����� ������ �޴´�.


#include <conio.h>



void UWorld::PlayerNameSelect(class UPlayer& _Player)
{
	// C:\\

	char InputName[100] = { 0, };

	bool IsNameInput = true;

	while (true)
	{
		if (true == IsNameInput)
		{
			system("cls");
			std::cout << "�̸��� �����ּ���" << std::endl;
			std::cin >> InputName;
		}

		system("cls");
		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");
		int Select = _getch();

		bool IsEnd = true;
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			IsEnd = false;
			IsNameInput = true;
			break;
		default:
			IsEnd = false;
			IsNameInput = false;
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");
			_getch();
			break;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	// ���� ����

	_Player.SetName(InputName);
}

void UWorld::ZoneInit()
{
	// �������� �غ��Ű��.
	// �̴ϼȶ����� �ܰ�
	// ��ü���� ����� ó������ �غ��Ű�� �ܰ�
	// ��κ� �� 1���Ѵ�.
	TownZone0.SetName("�ʺ�����");
	TownZone1.SetName("�߱޸���");
	FightZone.SetName("�ʺ������");

	//TownZone0.Connecting(&TownZone0);

	TownZone0.InterConnecting(&FightZone);

	// TownZone0.Connecting(&FightZone);
	// FightZone.Connecting(&TownZone0);

	// ��ĳ����
	// �������� 2�� 
	// ������ ������� �ֿ켱
	// �׽�Ʈ �ڵ带 ¥�� �մϴ�.
	// 2�� ���� ����ó�� �׽�Ʈ
	// ������ 
	//TownZone0.Link(&FightZone);
	//TownZone0.Link(&FightZone);

	// �׽���2
	//UTown Arr[100];
	//for (size_t i = 0; i < 100; i++)
	//{
	//	TownZone0.Link(&Arr[i]);
	//}
}


void UWorld::PlayerZonePlay(class UPlayer& _Player)
{
	ZoneInit();
	_Player.SetCurZone(0);
	_Player.SetGold(10000000);

	while (true)
	{
		int SelectZone = _Player.GetCurZone();

		switch (SelectZone)
		{
		case 0:
			TownZone0.InPlayer(_Player);
			break;
		case 1:
			TownZone1.InPlayer(_Player);
			break;
		case 2:
			FightZone.InPlayer(_Player);
			break;
		default:
			break;
		}
	}

}

void UWorld::InPlayer(class UPlayer& _Player)
{
	// �ܺα�� ����� �ְ� CPP�� ����. 
	UEngineFile File;
	File.SetPath("SaveFile.Dat");

	// ������ ������
	if (false == File.IsExits())
	{
		File.FileOpen("wb");

		// �̸� ���ϰ� ���Դ�.
		PlayerNameSelect(_Player);
		const char* Name = _Player.GetName();

		// ���ڿ��� �����Ҷ��� ������ �ִ�.
		// �ʹݿ��� �������� �ִ�.
		// �����Ҷ� ���� ���� ����� ũ�Ⱑ �����Ǿ� �ִ� ���̴�.
		File.Write(Name, NAMELEN);
	}
	else 
	{
		File.FileOpen("rb");

		char Arr[100] = {};
		File.Read(Arr, NAMELEN);
		_Player.SetName(Arr);
	}

	PlayerZonePlay(_Player);
}