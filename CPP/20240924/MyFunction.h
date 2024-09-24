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
 * 숫자의 자릿수를 계산하는 함수
 */
int NumberCount(int inNum)
{
    // 음수나 0인 경우 처리
    if (inNum <= 0) return 0;

    int result = 0;

    // 숫자를 10으로 나누면서 자릿수를 카운트
    while (inNum > 0)
    {
        inNum /= 10;
        result++;
    }

    return result;
}

/**
 * 문자를 합치는 함수
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
 * 숫자를 문자열로 변환하는 함수
 */
void NumberToString(char* outBuffer, int bufferSize, int value)
{
    // 버퍼 크기가 숫자의 자릿수보다 작으면 아무것도 하지 않음
    if (bufferSize <= NumberCount(value)) return;

    // 숫자의 자릿수 계산
    const int numCount = NumberCount(value);

    for (int i = numCount - 1; i >= 0; --i) {
        outBuffer[i] = 48 + (value % 10); // 마지막 자리수를 문자로 변환
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
