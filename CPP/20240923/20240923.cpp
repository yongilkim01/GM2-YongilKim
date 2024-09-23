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

int main()
{
    const char* testStr = "AAAAAAAAAA";

    std::cout << "String size using StringCount : " << StringCount(testStr) << std::endl;
    std::cout << "String size using strlen : " << strlen(testStr) << std::endl;

    return 0;
}
