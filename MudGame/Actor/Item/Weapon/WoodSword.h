#pragma once
#include "Weapon.h"


class WoodSword : public Weapon
{
	RTTI_DECLARATIONS(WoodSword, Weapon)
public:
	WoodSword(const char* name);
	virtual void Use() override;
private:
};