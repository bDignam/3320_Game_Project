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
    //PRE:  None
    //POST: Initializes Monster variables
    //      Picks random type of monster (3 types)
    //      Assigns corresponding weapon
    monster();

    //PRE:  None
    //POST: Copies monster by const reference
    monster(const monster&);

    //PRE:  None
    //POST: Subtracts dmg from health
    void takeDamage(int dmg);

    //PRE:  None
    //POST: Returns health
    const int getHealth() { return health; };

    //PRE:  None
    //POST: Returns name
    const std::string getName() { return name; };

    //PRE:  None
    //POST: Returns weapon
    const weapon getWeapon() { return myWeapon; };

    //PRE:  None
    //POST: Returns weapon damage if successful hit,
    //          otherwise returns 0
    const int strike() { return myWeapon.hit(); };

    //PRE:  None
    //POST: Copies monster by reference
    monster & operator = (const monster &mon);

private:
    int health;
    std::string name;
    weapon myWeapon;
};

#endif // MONSTER_H_INCLUDED
