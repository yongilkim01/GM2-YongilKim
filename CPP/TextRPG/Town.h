#pragma once
#include "Zone.h"
#include "BlackSmith.h"

class UTown : public UZone
{
	// �������̽� ����ȭ.
public:
	UTown();

	// ���������� �������� �̴ϴ�.
	// ���� ���� ���Ǵ� ���
	UZone* InPlayer(class UPlayer& _Player/*, int& Result*/);

	BlackSmith BS;
};

