/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename: monster.cpp
Purpose:
*/

#include "monster.h"

#include <time.h>
#include <cstdlib>
#include <iostream>

monster::monster()
{
    srand (time(NULL));
    int randInt = rand()%2;     //3 types of monsters

    if(randInt == 0)
    {
        name = "Troth";
        health = 13;
        myWeapon = weapon("Troth", 0.5, 5);
    }
    else if(randInt == 1)
    {
        name = "Gelfling";
        health = 6;
        myWeapon = weapon("Geff", 0.2, 4);
    }
    else
    {
        name = "Belf";
        health = 7;
        myWeapon = weapon("Beff", 0.35, 3);
    }
}

void monster::takeDamage(int dmg)
{
    try
    {
         health -= dmg;
         if (health < 0)
            throw health;
    }
    catch ( int h )         //Health cannot be negative
    {
        health = 0;
    }
}

monster::monster(const monster& mon)
{
    health = mon.health;
    myWeapon = mon.myWeapon;
    name = mon.name;
}

monster & monster::operator = (const monster &mon)
{
    health = mon.health;
    myWeapon = mon.myWeapon;
    name = mon.name;

    return *this;
}
