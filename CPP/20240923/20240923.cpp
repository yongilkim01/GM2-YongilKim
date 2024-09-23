#include <iostream>

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
}

int main()
{
    const char* testStr = "AAAAAAAAAA";

    std::cout << "String size using StringCount : " << StringCount(testStr) << std::endl;
    std::cout << "String size using strlen : " << strlen(testStr) << std::endl;

    std::cout << 1 << "의 자릿수 크기는 : " << NumberCount(1) << std::endl;
    std::cout << 12 << "의 자릿수 크기는 : " << NumberCount(12) << std::endl;
    std::cout << 123 << "의 자릿수 크기는 : " << NumberCount(123) << std::endl;
    std::cout << 1234 << "의 자릿수 크기는 : " << NumberCount(1234) << std::endl;
    std::cout << 12345 << "의 자릿수 크기는 : " << NumberCount(12345) << std::endl;
    std::cout << 123456 << "의 자릿수 크기는 : " << NumberCount(123456) << std::endl;
    std::cout << 1234567 << "의 자릿수 크기는 : " << NumberCount(1234567) << std::endl;
    
    const int bufferSize = 10;
    char strBuffer[bufferSize] = {0};
    NumberToString(strBuffer, bufferSize, 252424);

    std::cout << "str buffer의 문자열은 : " << strBuffer << std::endl;


    return 0;
}