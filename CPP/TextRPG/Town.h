#pragma once
#include "Zone.h"

class UTown : public UZone
{
	// �������̽� ����ȭ.
public:
	virtual int InPlayer(class UPlayer& _Player) override;
};

