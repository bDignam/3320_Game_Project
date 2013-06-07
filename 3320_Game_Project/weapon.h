/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename: weapon.h
Purpose:
*/

#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <string>

class weapon
{
public:
    weapon();
    weapon(std::string, double, int);
    weapon(const weapon&);

    std::string getName() { return name; };
    //const int getDmg() { return damage; };
    //const double getChance() { return chance; };

    const int hit();

    weapon & operator = (const weapon &wep);

    friend std::ostream& operator << (std::ostream &, const weapon&);

private:
    std::string name;
    double chance;
    int damage;
};

#endif // WEAPON_H_INCLUDED
