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

    //PRE:  NOT run on Linux
    //POST: Waits INT amount of milliseconds
    void sleepFunc(unsigned int);

    //PRE:  None
    //POST: Prints formatted Player stats list
    void print_Score_Screen();

    //PRE:  room* r exists
    //POST: Sets currentRoom pointer to the new room r
    void setCurrentRoom(room* r) {currentRoom = r;};

    //PRE:  None
    //POST: Adds tre to Player's Treasure
    void addTreasure(int tre) { treasure += tre; };

    //PRE:  None
    //POST: Subtracts dam from Player's health
    void takeDamage(int dam) { health -= dam; };

    //PRE:  None
    //POST: Returns Player's health
    const int getHealth() { return health; };

    //PRE:  None
    //POST: Returns Player's treasure
    const int getTreasure() { return treasure; };

    //PRE:  None
    //POST: Returns # of monsters killed
    const int getMonstersKilled() {return monstersKilled; };

    //PRE:  None
    //POST: Returns Player's Weapon's name
    const std::string getWeaponName() { return myWeapon.getName(); } ;

    //PRE:
    //POST:
    const int strike() { return myWeapon.hit(); };

    //PRE:
    //POST:
    bool combat();

    //PRE:
    //POST:
    room * getCurr() {return currentRoom;};

    //PRE:
    //POST:
    bool moveNextRoom();

    //PRE:
    //POST:
    template <typename T>
        void printCombatHeader(T, T, T, T);



private:
    int health;
    int treasure;
    int monstersKilled;
    weapon myWeapon;
    room * currentRoom;
};


#endif // PLAYER_H_INCLUDED
