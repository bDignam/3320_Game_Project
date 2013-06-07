/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename: monster.h
Purpose:
*/

#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "weapon.h"

#include <string>

class monster
{
public:
    monster();
    monster(const monster&);

    void takeDamage(int dmg) { health -= dmg; };

    const int getHealth() { return health; };
    const std::string getName() { return name; };
    const weapon getWeapon() { return myWeapon; };
    const int strike() { return myWeapon.hit(); };

    monster & operator = (const monster &mon);

private:
    int health;
    std::string name;
    weapon myWeapon;
};

#endif // MONSTER_H_INCLUDED
