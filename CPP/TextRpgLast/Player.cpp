#include "Player.h"
#include <iostream>

APlayer::APlayer()
{
	UObject* ObjectPtr = this;
	UStatusUnit* StatusUnitPtr = this;
	UFightUnit* FightUnitPtr = this;
}

void APlayer::StatusTextRender()
{
	printf_s("���ݷ� : %d ~ %d + %d\n", MinAtt, MaxAtt, EquipAtt);
	printf_s("ü�� : %d\n", Hp);
	printf_s("��� : %d\n", Gold);
}
