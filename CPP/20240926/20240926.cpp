// TextRPG002inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

const int NAMELEN = 10;
const int LINECOUNT = 50;

class StatusUnit
{
protected:
    char Name[NAMELEN] = "NONE";
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;
    int Charm = 0;
};


class FightUnit : public StatusUnit
{
public:

    // MinMax
    int GetDamage() const
    {
        srand(static_cast<unsigned int>(time(0)));
        return MinAtt + (rand() % (MaxAtt - MinAtt + 1));
    }

    // 클래스의 레퍼런스를 넣어주는것이 많은게 간단해 집니다.
    void DamageLogic(const FightUnit& _AttUnit)
    {
        // _AttUnit => 나를 공격하려는 상대
        Hp -= _AttUnit.GetDamage();
    }

    void DamageRender(const char* const _AttName, int _Att)
    {
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, Name, _Att);
    }

    void StatusRender()
    {
        printf_s("%s Status", Name);
        int nameLineCount = LINECOUNT - strlen(Name) - strlen(" Status");
        for (int i = 0; i < nameLineCount; i += 1)
        {
            printf_s("-");
        }
        printf_s("\n");
        printf_s("최소 공격력 : %d\n", MinAtt);
        printf_s("최대 공격력 : %d\n", MaxAtt);
        printf_s("체력 : %d\n", Hp);

        for (int i = 0; i < LINECOUNT; i += 1)
        {
            printf_s("-");
        }
        printf_s("\n");

        // printf_s("---------------------------------------------------\n");
    }

    const char* GetName() const
    {
        return Name;
    }

protected:


private:
};

// 컴포넌트 방식이라는 것과 차이가 거의 없다.
// 보통 상속구조와 컴포넌트 기반구조가 게임의 로직계를 지배하고 있다.
// 

class Player : public FightUnit
{
public:
    Player(const char* _Name)
    {
        strcpy_s(Name, _Name);
    }
};

class Monster : public FightUnit
{
public:
    Monster(const char* _Name)
    {
        strcpy_s(Name, _Name);
    }
};


// 게임을 만들다보면
// 일반적인 로직클래스 Player
// 리소스 클래스 <= 
// 데이터 전담클래스가 <= 내부에 변수밖에 없다. 
// 맴버변수도 public을 사용합니다.

int main()
{

    Player NewPlayer("Player");
    Monster NewMonster("Orc");
    NewMonster.DamageLogic(NewPlayer);

    NewPlayer.StatusRender();
    NewMonster.StatusRender();

    // NewPlayer.
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
