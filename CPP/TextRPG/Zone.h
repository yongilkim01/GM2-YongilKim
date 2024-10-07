#pragma once
#include "StatusUnit.h"
#include "ContentsConst.h"

// �������� ������ ū�� ���ϴ�.
class UZone : public UObject
{
public:
	void InMsgPrint();
	void ZonePrint();
	// ������ ������ �����Ѵ�.
	// bool ���� �� ������ ����ɼ� ���ٸ�

	bool InterConnecting(UZone* _LinkZone);

	bool Connecting(UZone* _LinkZone);

	// �� ������ ����Ǿ� �ִ�?
	bool IsConnecting(UZone* _LinkZone);

	void ConnectingPrint();

	UZone* ConnectingProgress();

	// ���� �̳༮ ��ü�� �ƹ��͵� ���� �ʽ��ϴ�.
	// �θ�� �������̽��� �����Ѵٰ� �մϴ�.
	virtual UZone* InPlayer(class UPlayer& _Player) 
	{
		return nullptr;
	}

protected:


private:
	// � Ŭ���� �ڽ��� ���ο� 
	// ���ο��� ����� ���� ������ ������ ��� ��������
	// ���δ� ���⿡ �������� �ִ�.
	UZone* LinkZone[LINKZONEMAX] = {nullptr,};
	//UTown* LinkZone[LINKZONEMAX] = { nullptr, };
	//UFightZone* LinkZone[LINKZONEMAX] = { nullptr, };

	//UZone* LinkZone;
	//__int64 LinkIndex;

	// __int64 LinkZone[LINKZONEMAX]
	int SelectMax = 0;
};