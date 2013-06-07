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

    //PRE:  None
    //POST: Creates generic weapon
    weapon();

    //PRE:  None
    //POST: Sets name to string, chance to double, damage to int
    weapon(std::string, double, int);

    //PRE:  None
    //POST: Copies weapon by reference
    weapon(const weapon&);

    std::string getName() { return name; };

    //PRE:  None
    //POST: Returns damage if successful hit,
    //          otherwise returns 0
    //      Throws exception and Aborts if random-number is below 0
    const int hit();

    //PRE:  None
    //POST: Copies weapon by reference
    weapon & operator = (const weapon &wep);

    //PRE:  None
    //POST: Prints weapon name
    friend std::ostream& operator << (std::ostream &, const weapon&);

private:
    std::string name;
    double chance;
    int damage;
};

#endif // WEAPON_H_INCLUDED
