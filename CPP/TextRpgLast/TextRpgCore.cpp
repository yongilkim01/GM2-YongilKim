#include "TextRpgCore.h"
#include "Player.h"
#include "World.h"
#include <iostream>

// �÷��̾�� �� 1���̴�.
APlayer MainPlayer;
UWorld World;

APlayer& TextRpgCore::GetPlayer()
{
	return MainPlayer;
}

TextRpgCore::TextRpgCore()
{

}

void TextRpgCore::Start()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	MainPlayer.SetName("MainPlayer");
	World.ZoneInit();
	World.PlayerZonePlay();
}