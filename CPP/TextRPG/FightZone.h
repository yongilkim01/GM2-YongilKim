#pragma once
#include "Zone.h"

// ������ ��Ű��ó
class UFightZone : public UZone
{
public:
	virtual int InPlayer(class UPlayer& _Player) override;
};

