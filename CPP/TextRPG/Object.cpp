#include "Object.h"



void UObject::SetName(const char* const _Name)
{
    if (NAMELEN <= strlen(_Name))
    {
        MSGASSERT("�̸��� �ʹ� ��ϴ�");
        return;
    }

    strcpy_s(Name, _Name);
}