// 20241010.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class UStatusUnit
{
public:
    UStatusUnit()
    {
        std::cout << "UStatusUnit 생성자" << std::endl;
    }

    virtual void BeginPlay() 
    {
        std::cout << "UStatusUnit begin play" << std::endl;
    }

    ~UStatusUnit()
    {
        std::cout << "UStatusUnit 소멸자" << std::endl;
    }
};

class UFightUnit
{
public:
    UFightUnit()
    {
        std::cout << "UFightUnit 생성자" << std::endl;
    }

    virtual void BeginPlay() 
    {
        std::cout << "UFightUnit begin play" << std::endl;
    }

    virtual ~UFightUnit()
    {
        std::cout << "UFightUnit 소멸자" << std::endl;
    }
};

class UObject
{
public:
    UObject()
    {
        std::cout << "UObject 생성자" << std::endl;
    }

    virtual void BeginPlay()
    {
        std::cout << "UObject begin play" << std::endl;
    }

    ~UObject()
    {
        std::cout << "UObject 소멸자" << std::endl;
    }
};

class AActor : public UObject, public UFightUnit, public UStatusUnit
{
public:
    AActor()
    {
        std::cout << "AActor 생성자" << std::endl;
    }

    virtual void BeginPlay() override = 0
    {
        UObject::BeginPlay();
        UFightUnit::BeginPlay();
        UStatusUnit::BeginPlay();
        std::cout << "AActor begin play" << std::endl;
    }

    virtual ~AActor()
    {
        std::cout << "AActor 소멸자" << std::endl;
    }
};

class AMonster : public AActor
{
public:
    AMonster()
    {
        std::cout << "AMonster 생성자" << std::endl;
    }

    virtual void BeginPlay() override = 0
    {
        AActor::BeginPlay();
        std::cout << "Monster begin play" << std::endl;
    }

    virtual ~AMonster()
    {
        std::cout << "AMonster 소멸자" << std::endl;
    }
};

class AOrc : public AMonster
{
public:
    AOrc()
    {
        std::cout << "AOrc 생성자" << std::endl;
    }

    virtual void BeginPlay() override
    {
        AMonster::BeginPlay();
        std::cout << "orc begin play" << std::endl;
    }

    virtual ~AOrc()
    {
        std::cout << "AOrc 소멸자" << std::endl;
    }
};

int main()
{
    UStatusUnit* orc = new AOrc();
    //int size = sizeof(AOrc);
    orc->BeginPlay();

    delete orc;
}