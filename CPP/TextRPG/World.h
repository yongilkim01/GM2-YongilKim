#pragma once

class UZone;

class UWorld
{
public:
	void InPlayer(class UPlayer& _Player);

private:
	void PlayerNameSelect(class UPlayer& _Player);
	void PlayerZonePlay(class UPlayer& _Player);

private:
	UZone* CurrentZone = nullptr;
};

