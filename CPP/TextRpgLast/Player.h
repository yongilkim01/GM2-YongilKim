#pragma once
#include "Actor.h"

// UObject �̸�
// UStatusUnit�� ���ؼ� �ɷ�ġ
// UFightUnit�� ���ؼ� ����
class APlayer : public AActor
{
	// �Ϻη� ����

public:
	APlayer();

	inline int GetEquipAtt() const
	{
		return EquipAtt;
	}

	inline void SetEquipAtt(int _Value)
	{
		EquipAtt = _Value;
	}

	void StatusTextRender() override;

private:
	int EquipAtt = 0;
};

