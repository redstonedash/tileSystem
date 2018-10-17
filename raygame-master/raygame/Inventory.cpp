#include "InventoryManagment.h"
#include "raylib.h"
#include <iostream>

Inventory::Inventory()
{
}

Inventory Inventory::operator+(Item item)
{
	for (int i = 0; i < 64; i++) {
		if (inventory[i].Type == '\0') {
			inventory[i] = item;
			break;
		}
	}
	return *this;
}

Inventory Inventory::operator-(Item item)
{
	for (int i = 0; i < 64; i++) {
		if (inventory[i] == item) {
			inventory[i] = Item();
			break;
		}
	}
	return Inventory();
}
Inventory Inventory::operator+=(Item i)
{
	return (*this + i);
}

Inventory Inventory::operator-=(Item i)
{
	return (*this - i);
}

void Inventory::draw(int x, int y)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (inventory[i+8*j].Type != '\0')
			{
				inventory[i+8*j].draw(i * 32 + x, j * 32 + y);
			}
		}
	}
	return;
}
