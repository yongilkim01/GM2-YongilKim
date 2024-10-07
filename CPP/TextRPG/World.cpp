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

	TownZone0.InterConnecting(&FightZone);
}


void UWorld::PlayerZonePlay(class UPlayer& _Player)
{
	// �ʵ� �غ�ư�
	// �÷��̾ �� �Ȼ�Ȳ����
	
	// 100����
	//UTown TownZone0;
	// __int64 LinkZone[LINKZONEMAX]
	// [0] 200 => �ʺ������
	// 
	// 150���� 
	//UTown TownZone1;
	// 200���� �ʺ������
	//UFightZone FightZone;
	// [0] 100 => �ʺ�����


	// ������ 8����Ʈ �����Դϴ�.
	// 100����
	UZone* CurZone = &TownZone0;

	while (true)
	{
		// �����ʹ� ��ü�� �ƴϰ�
		// �׳� �ּҰ��� ���̴�. �������� ����ɼ� �ִ�.
		// UZone������ �ڽ��� �Լ����� ����˴ϴ�.
		CurZone = CurZone->InPlayer(_Player);
	}
}

// �������� �ʿ��� ���
// UPlayer �ο�� ��ų���� 
// �̸��̳� 
void UWorld::PlayerInit(class UPlayer& _Player)
{
	// �÷��̾ �غ��Ű�� ��.
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
	//_Player.SetGold(10000);
}

void UWorld::InPlayer(class UPlayer& _Player)
{
	// ���ʿ䰡 ����.
	// �÷��̾ �غ��Ű��
	PlayerInit(_Player);

	// ���� �غ��Ų��.
	ZoneInit();
	// �÷���
	PlayerZonePlay(_Player);
}