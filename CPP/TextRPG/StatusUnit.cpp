#include "StatusUnit.h"
#include <BaseSystem/EngineDebug.h>
#include <iostream>

void UStatusUnit::StatusRender()
{
    // ��Ӱ��迡�� �ڽ��� �����ϴµ�.
    // ���� �Լ��� ����Կ��� �ڽĵ鸶�� �ٸ� ������ �ؾ��Ҷ� ����ϴ� ����
    // virtual 
    
    // ������ �޴°� �����ؼ�.
    const char* Name = GetName();
    //printf_s("%s Status", GetName());
    //int NameLan = static_cast<int>(strlen(GetName()));
    printf_s("%s Status", Name);
    int NameLan = static_cast<int>(strlen(Name));
    int StatusRand = static_cast<int>(strlen(" Status"));
    int nameLineCount = LINECOUNT - NameLan - StatusRand;
    for (int i = 0; i < nameLineCount; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
    printf_s("���ݷ� : %d ~ %d\n", MinAtt, MaxAtt);
    printf_s("ü�� : %d\n", Hp);

    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
}

