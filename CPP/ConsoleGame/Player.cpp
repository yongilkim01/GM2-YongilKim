#include "Player.h"
#include <conio.h>
#include "Enums.h"

void Player::BeginPlay(FIntPoint _Value)
{
	PlayerImage.Create({3, 5}, '@');
	WindowSize = _Value;
}

void Player::Tick()
{
	int Value = _kbhit();
	Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			Dir = Enums::GAMEDIR::LEFT;
			break;
		case 'D':
		case 'd':
			Dir = Enums::GAMEDIR::RIGHT;
			break;
		case 'W':
		case 'w':
			Dir = Enums::GAMEDIR::UP;
			break;
		case 'S':
		case 's':
			Dir = Enums::GAMEDIR::DOWN;
			break;
		default:
			break;
		}

	}

	switch (Dir)
	{
	case Enums::GAMEDIR::LEFT:
		if (Pos.X - 1 >= 0)
		{
			Pos += FIntPoint::LEFT;
		}
		break;
	case Enums::GAMEDIR::RIGHT:
		if (Pos.X + PlayerImage.GetImageSizeX() < WindowSize.X)
		{
			Pos += FIntPoint::RIGHT;
		}
		break;
	case Enums::GAMEDIR::UP:
		if (Pos.Y - 1 >= 0)
		{
			Pos += FIntPoint::UP;
		}
		break;
	case Enums::GAMEDIR::DOWN:
		if (Pos.Y + PlayerImage.GetImageSizeY() < WindowSize.Y)
		{
			Pos += FIntPoint::DOWN;
		}

		break;
	default:
		break;
	}

	// Pos += FIntPoint::RIGHT;
}

void Player::Render(ConsoleImage* _BackBuffer)
{
	// delete _BackBuffer;
	_BackBuffer->Copy(Pos, PlayerImage);
}

void Player::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}