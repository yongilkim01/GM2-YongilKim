#pragma once
#include "StatusUnit.h"
#include "ContentsConst.h"

// �������� ������ ū�� ���ϴ�.
class UZone : public UObject
{
public:
	void InMsgPrint();

	// ������ ������ �����Ѵ�.
	// bool ���� �� ������ ����ɼ� ���ٸ�

	bool InterConnecting(UZone* _LinkZone);

	bool Connecting(UZone* _LinkZone);

	// �� ������ ����Ǿ� �ִ�?
	bool IsConnecting(UZone* _LinkZone);

	// void LinkPrint();

protected:


private:
	// � Ŭ���� �ڽ��� ���ο� 
	// dhkswjs 
	UZone* LinkZone[LINKZONEMAX] = {nullptr,};
};