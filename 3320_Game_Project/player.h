/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename: player.h
Purpose:
*/


#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>

#include "weapon.h"
#include "room.h"

class player
{
public:
    player();

    void sleepFunc(unsigned int);

    void print_Score_Screen();

    void setCurrentRoom(room* r) {currentRoom = r;};

    void addTreasure(int tre) { treasure += tre; };
    void takeDamage(int dam) { health -= dam; };

    const int getHealth() { return health; };
    const int getTreasure() { return treasure; };
    const int getMonstersKilled() {return monstersKilled; };
    const std::string getWeaponName() { return myWeapon.getName(); } ;
    const int strike() { return myWeapon.hit(); };

    bool combat();

    room * getCurr() {return currentRoom;};

    bool moveNextRoom();



private:
    int health;
    int treasure;
    int monstersKilled;
    weapon myWeapon;
    room * currentRoom;
};


#endif // PLAYER_H_INCLUDED
