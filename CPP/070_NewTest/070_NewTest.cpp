// 070_NewTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    "&&**";
    "&&**";
    "****";
    "****";


    // 정적 바인딩 배열은 변수를 넣어서 사용할수가 없습니다.
    // char Arr[ImageScaleY];

    // 동적할당 배열을 만들때는 상수를 넣지 않아도 됩니다.
    int ImageScaleY = 4;
    char** AllImagePixel = new char* [ImageScaleY] {0,};
    char* Arr[4];

    int ImageScaleX = 4;
    AllImagePixel[0] = new char[ImageScaleX + 1];
    AllImagePixel[1] = new char[ImageScaleX + 1];
    AllImagePixel[2] = new char[ImageScaleX + 1];
    AllImagePixel[3] = new char[ImageScaleX + 1];


    delete[] AllImagePixel[3];
    AllImagePixel[3] = nullptr;

    delete[] AllImagePixel[2];
    AllImagePixel[2] = nullptr;

    delete[] AllImagePixel[1];
    AllImagePixel[1] = nullptr;

    delete[] AllImagePixel[0];
    AllImagePixel[0] = nullptr;
   

    if (nullptr != AllImagePixel)
    {
        delete[] AllImagePixel;
        AllImagePixel = nullptr;
    }

    // char* ImageLinePtr = new char[5];



    // char** ImagePtr = new char*[4 * 4 + 1];
}
