#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "Weapon.h"
#include <iostream>
#include <string>
#include <map>
// Your code here

class Enemy {
protected:
	int MAX_HEALTH;
	int health;
	int armor;
	int attackPower;
	std::unique_ptr<Weapon> weapon;


public:

	Enemy(int hp, int, int maxHp, int armor, int dmg);
	virtual void shoot() = 0;
	virtual void takeDamage(int &dmg);
	virtual void voiceLines() = 0;

	void equipWeapon(std::unique_ptr<Weapon> newWeapon);
};

class B1StandardBattleDroid : public Enemy{
	B1StandardBattleDroid();
	B1StandardBattleDroid(const B1StandardBattleDroid& other);

	void shoot() override;
	void voiceLines() override;
	void takeDamage(int &dmg) override;

};
class B1CommanderBattleDroid : public Enemy {

};
class B2StandardDroids : public Enemy {

};
class B2HeavyDroids : public Enemy {

};
class Droidika : public Enemy {

};
class TacticalDroid : public Enemy {

};
class MagnaGuard : public Enemy {

};

#endif // ITEM_H 
/*
Potential Enemys's
	- B1 Battle Droid
	- B2 Super Battle Droid
	- Droidika
	- Commando droid
	- BX-series Droid Commando
	- Dwarf spider droid 
	- Halifire Droid
	- Vulture droid
	- Octuparra
	- Tactical Droid 
	- droid with the double edged spear

	- Mainly the above are classic star wras droids , but will make custome / own enemy's 
	- boss battles / mini boss will not necesarily be one big enmey but multiple
*/

/*
Potential Functions
	- genral functions for all droids
	- global to all droids
		- health 
		- damage  ( taking and doing)
		- voice lines, potentiall aroudn 50-100 maybe more which we will genrtae via AI so then for randomisation it will help a lot for different scnarios or same scnario just difference words
		- Weapons , reason this is global is becuase we will also make custom droids or not even use any of the oringla star wars droids , so custome droids could have any potential weapon
		- 





*/