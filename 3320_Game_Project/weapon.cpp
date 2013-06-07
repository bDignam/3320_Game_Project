/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename: weapon.cpp
Purpose:
*/

#include "weapon.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

weapon::weapon()
{
    name = "Weapon";
    chance = 0.75;
    damage = 5;
}

weapon::weapon(std::string newName, double newChance, int newDamage)
{
    name = newName;
    chance = newChance;
    damage = newDamage;
}

weapon::weapon(const weapon& wep)
{
    name = wep.name;
    chance = wep.chance;
    damage = wep.damage;
}

const int weapon::hit()
{
    try
    {
        srand (time(NULL));
        int randInt = rand()%100;
        if( randInt < (chance * 100) )
            return damage;  //HIT
        else if ( randInt < 0 )
            throw randInt;  //Random integer error
        else
            return 0;       //MISS
    }
    catch (int badNum)
    {
        std::cerr << "\n\nIn function weapon::hit()\n";
        std::cerr << "  randInt:  " << badNum << " is Out-Of-Bounds.\n";
        std::cerr << "Aborting...\n";
        abort();
    }
}

weapon & weapon::operator = (const weapon &wep)
{
    name = wep.name;
    chance = wep.chance;
    damage = wep.damage;

    return *this;
}

std::ostream& operator << (std::ostream& out, const weapon& tempWeapon)
{
    return out << tempWeapon.name;
}
