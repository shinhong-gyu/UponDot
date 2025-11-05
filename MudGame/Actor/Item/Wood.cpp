#include "Wood.h"

Wood::Wood(const char* name)
	: Item("name")
{
	itemType = ItemType::Wood;
}

Wood::~Wood()
{
}

void Wood::Use()
{
}
