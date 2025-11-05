#pragma once
#include "Item.h"


class Medicine : public Item
{
	RTTI_DECLARATIONS(Medicine, Item)

public:
	Medicine(const char* name, Player* owner);
	~Medicine();

	virtual void Use() override;
private:
};