#pragma once
#include<iostream>

const int LINECOUNT = 50;
const int NAMELEN = 10;

int PlayerAttack = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAttack = 10;
int MonsterHp = 100;
char MonsterName[NAMELEN] = "NONE";

int StringCount(const char* const inStr)
{
    int strCount = 0;
    while (inStr[strCount])
    {
        strCount++;
        if (inStr[strCount] == '\0') break;
    }

    return strCount;
}

/**
 * ������ �ڸ����� ����ϴ� �Լ�
 */
int NumberCount(int inNum)
{
    // ������ 0�� ��� ó��
    if (inNum <= 0) return 0;

    int result = 0;

    // ���ڸ� 10���� �����鼭 �ڸ����� ī��Ʈ
    while (inNum > 0)
    {
        inNum /= 10;
        result++;
    }

    return result;
}

/**
 * ���ڸ� ��ġ�� �Լ�
 *
 */
void PlusString(char* outBuffer, int bufferSize, int strCount, ...)
{
    int currentValueIdx = 3;
    unsigned __int64 pValue = reinterpret_cast<unsigned __int64>(&outBuffer);
    int argsLength = *(reinterpret_cast<int*>(pValue + 16));
    int outStrCount = 0;

    for (int i = 0; i < argsLength; i++)
    {
        char* value = *(reinterpret_cast<char**>(pValue + (8 * currentValueIdx)));
        currentValueIdx++;
        int inStrCount = 0;
        while (value[inStrCount] != '\0')
        {
            outBuffer[outStrCount] = value[inStrCount];
            outStrCount++;
            inStrCount++;
        }
    }

    return;
}

/**
 * ���ڸ� ���ڿ��� ��ȯ�ϴ� �Լ�
 */
void NumberToString(char* outBuffer, int bufferSize, int value)
{
    // ���� ũ�Ⱑ ������ �ڸ������� ������ �ƹ��͵� ���� ����
    if (bufferSize <= NumberCount(value)) return;

    // ������ �ڸ��� ���
    const int numCount = NumberCount(value);

    for (int i = numCount - 1; i >= 0; --i) {
        outBuffer[i] = 48 + (value % 10); // ������ �ڸ����� ���ڷ� ��ȯ
        value /= 10;
    }

    return;
}

void MyPrintf(const char* const inPtr, ...)
{
    int chCount = 0;
    int currentValueIdx = 1;
    const int bufferSize = 10;
    char strBuffer[bufferSize] = { 0 };
    unsigned __int64 pValue = reinterpret_cast<unsigned __int64>(&inPtr);

    while (inPtr[chCount])
    {
        if (inPtr[chCount] == '%')
        {
            chCount++;
            switch (inPtr[chCount])
            {
            case 'd':
            {
                int value = *(reinterpret_cast<int*>(pValue + (8 * currentValueIdx)));
                currentValueIdx++;

                NumberToString(strBuffer, bufferSize, value);

                for (int i = 0; i < NumberCount(value); i++)
                {
                    putchar(strBuffer[i]);
                }
                break;
            }
            case 'c':
            {
                char value = *(reinterpret_cast<char*>(pValue + (8 * currentValueIdx)));
                currentValueIdx++;
                putchar(value);
                break;
            }
            case 's':
            {
                int strCount = 0;
                char* value = *(reinterpret_cast<char**>(pValue + (8 * currentValueIdx)));
                currentValueIdx++;
                while (value[strCount] != '\0')
                {
                    putchar(value[strCount]);
                    strCount++;
                }
                break;
            }
            default:
                break;
            }
            chCount++;
        }
        else {
            putchar(inPtr[chCount]);
            chCount++;
        }
    }
    return;
}
