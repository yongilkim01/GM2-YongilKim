#pragma once
// ���ϰ��� �߻����ϸ鼭
#include "ContentsConst.h"
#include <BaseSystem/EngineDebug.h>
#include <iostream>

class UObject
{
public:
	void SetName(const char* const _Name);
	inline const char* GetName()
	{
		return Name;
	}

	// �θ��ڽİ�����
	// ��ų�� �θ� ���Ȱ�� 
//protected:
//	char Name[NAMELEN] = "NONE";
	// UPlayer* Player;

private:
	char Name[NAMELEN] = "NONE";
};