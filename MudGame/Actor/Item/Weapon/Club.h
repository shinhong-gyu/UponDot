#pragma once
#include "Weapon.h"

class Club : public Weapon
{
	RTTI_DECLARATIONS(Club, Weapon)
public:
	Club(const char* name);
	virtual void Use() override;
private:
};