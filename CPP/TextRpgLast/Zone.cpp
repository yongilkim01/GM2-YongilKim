#include "Zone.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "�� �����߽��ϴ�.\n";
}

void UZone::ZonePrint()
{
	std::cout << GetName() << "�� ü����.\n";
}

bool UZone::IsConnecting(UZone* _ConnectingZone)
{
	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (_ConnectingZone == ConnectingZones[i])
		{
			return true;
		}
	}

	return false;
}

// 100�� 25�ж� �ȵƾ� ������ ����.
// 50�ж� �� �ȵƾ� �� ����
// �ƿ� ��Ʈ�� ����. => ���� ���� ����ص� 

bool UZone::InterConnecting(UZone* _LinkZone)
{
	// 2���̸� �˴ϴ�.
	// ������ּ���.
	// �⺻�� ������ �⺻�Դϴ�.
	// �����ϰ� ¥����.
	// �����
	_LinkZone->Connecting(this);
	this->Connecting(_LinkZone);

	return true;
}

bool UZone::Connecting(UZone* _LinkZone)
{
	if (this == _LinkZone)
	{
		MSGASSERT("�ڱ��ڽ��� �ڽſ��� �����Ϸ��� �߽��ϴ�.");
		return false;
	}


	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("�̹� ����� ������ ���� ������ �� �����Ϸ��� �߽��ϴ�.");
		return false;
	}

	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr == ConnectingZones[i])
		{
			ConnectingZones[i] = _LinkZone;
			SelectMax += 1;
			// ���� ����
			// _LinkZone->Link(this);
			return true;
		}
	}

	MSGASSERT("�̹� ��� ������ �ϰ�� �����̶� ���ῡ �����߽��ϴ�.");
	return false;
}

UZone* UZone::ConnectingProgress()
{

	while (true)
	{
		ConnectingPrint();

		// 2�� ������ �Ǿ��ִٶ�� �����غ���.
		int Select = _getch();
		Select -= '0';

		// 2���̶� ����Ǿ� ������ 
		// 1~2�����϶�
		if (Select >= 1 && Select <= SelectMax)
		{
			return ConnectingZones[Select - 1];
		}
		else if(Select <= (SelectMax + 1))
		{
			return this;
		}
	}

	return nullptr;
}

void UZone::ConnectingPrint()
{
	system("cls");

	int StartIndex = 1;

	// 1. �ʺ�����
	// 2. �����
	// 3. 
	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr != ConnectingZones[i])
		{
			const char* NamePtr = ConnectingZones[i]->GetName();
			// char Number[100];
			// itoa(StartIndex, Number, )
			//%s char* �־��ָ� �ٿ��� ����� ���ش�.
			printf_s("%d. %s�� �̵�.\n", StartIndex, NamePtr);
			StartIndex += 1;
		}
	}

	printf_s("%d. %s�� ���ư���.\n", StartIndex, GetName());
}