#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"


class Weapon : public Item {
protected:
	int damage;
	int currentAmmo;
	int ammoCapacity;
public:
	Weapon(int dmg, int ammo, int maxAmmo);
	virtual int fire(std::string user ,bool isPlayer);
};

class Blaster : public Weapon {
	Blaster();
};
/*
- damage 
- maybe durability for certain weapons (limited uses)
- weight and size , depedning on these factors certain actions may fail , be slover , faster or eleiminate certain dialigue / choices as a whole etc
*/

#endif // ITEM_H