#pragma once

// ��� enum�� ���⿡ ��� ���´�.

class Enums
{
	// �������� �����ڴ� �߿��ϴ�.
	// MAXS�� ����Ҽ� ���� �ȴ�.
public:
	enum class MAXS
	{
		NAMEMAX = 256,
		ACTORNAMEMAX = 10,
		ZONELINKMAX = 5,
		LINECOUNT = 50
	};

	enum class MONSTERTYPE
	{
		// �Ǽ������� Ȯ���ϱ� ���ؼ�
		NONE = 0,
		GOBLIN,
		ORC
	};

};
