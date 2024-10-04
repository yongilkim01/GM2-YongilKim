#pragma once
#include "Zone.h"

class UTown : public UZone
{
	// 인터페이스 통일화.
public:
	virtual int InPlayer(class UPlayer& _Player) override;
};

