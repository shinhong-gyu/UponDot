#include "WoodSword.h"
#include "Game/Game.h"
#include "Actor/Player.h"
#include "../Meat.h"

WoodSword::WoodSword(const char* name)
	: Weapon("¸ñ °Ë")
{
	itemType = ItemType::WoodSword;
}

void WoodSword::Use()
{
	float randNo = RandomPercent(0.0f, 1.0f);
	if (randNo <= 0.2f)
	{
		Game::Get().player->SetHP(Game::Get().player->GetHP() - 3);
		Game::Get().PrintLoseImage();
	}
	else
	{
		Game::Get().player->AddToInventory(ItemType::Meat, 1);
		Game::Get().PrintWinImage();
	}
}
