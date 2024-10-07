#include "Zone.h"
#include <conio.h>
#include <BaseSystem/EngineDebug.h>

void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "�� �����߽��ϴ�.\n";
}

void UZone::ZonePrint()
{
	std::cout << GetName() << "�� ü����.\n";
}

bool UZone::IsConnecting(UZone* _LinkZone)
{
	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (_LinkZone == LinkZone[i])
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

	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (nullptr == LinkZone[i])
		{
			LinkZone[i] = _LinkZone;
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
			return LinkZone[Select - 1];
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
	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (nullptr != LinkZone[i])
		{
			const char* NamePtr = LinkZone[i]->GetName();
			// char Number[100];
			// itoa(StartIndex, Number, )
			//%s char* �־��ָ� �ٿ��� ����� ���ش�.
			printf_s("%d. %s�� �̵�.\n", StartIndex, NamePtr);
			StartIndex += 1;
		}
	}
}