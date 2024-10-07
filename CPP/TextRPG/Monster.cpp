#include "Monster.h"


void UMonster::PrintStatus()
{
	printf_s("몬스터 공격력 : %d ~ %d\n", MinAtt, MaxAtt);
	printf_s("몬스터 체력 : %d\n", Hp);
}
