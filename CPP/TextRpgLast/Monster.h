#pragma once
#include "Actor.h"

// ��� �߻����� ��������?
// ������ ���� �߻����� �������� ��üȭ �Ҽ� ����.
class AMonster : public AActor
{
public:
	// �����Լ�
	virtual void BeginPlay() = 0;

	void SetRandomGold(int _Min, int _Max);

};

