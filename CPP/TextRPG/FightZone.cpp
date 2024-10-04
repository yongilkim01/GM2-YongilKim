#include "FightZone.h"
#include <conio.h>
#include "Player.h"

int UFightZone::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();

	while (true)
	{
		// 미리 헤더를 #include 최대한 미루는게 좋다.
		_Player.StatusRender();

		std::cout << "0. 체력회복\n";
		std::cout << "1. 강화\n";
		std::cout << "2. 초보마을로 이동\n";
		std::cout << "3. 중급마을로 이동\n";
		std::cout << "4. 사냥터이동\n";
		int Select = _getch();

		switch (Select)
		{
		case '0':
			printf_s("0눌렀습니다.");
			_getch();
			break;
		case '1':
			printf_s("1눌렀습니다.");
			_getch();
			break;
		case '2':
		{
			printf_s("2 눌렀습니다.");
			_getch();
			return 2;
			break;
		}
		case '3':
			printf_s("3 눌렀습니다.");
			_getch();
			return 3;
		case '4':
			printf_s("4 눌렀습니다.");
			_getch();
			return 4;
		default:
			break;
		}

	}

	return 0;
}