#include "Zone.h"
#include <conio.h>


void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << " �� �����߽��ϴ�.\n";
}

int UZone::InPlayer(UPlayer& _Player)
{
	return 0;
}
