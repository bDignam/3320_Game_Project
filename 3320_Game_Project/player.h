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
    //PRE:  None
    //POST: Initializes Player variables
    //      Gives random weapon
    //      Sets Room = NULL
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
    //POST: Subtracts dmg from Player's health
    void takeDamage(int dmg);

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

    //PRE:  None
    //POST: Returns Weapon Damage, or 0, based on weapon's Chance to hit
    const int strike() { return myWeapon.hit(); };

    //PRE:  Current Room has a Monster in it
    //POST: Returns True if Player wins
    //      Returns False if Player dies
    bool combat();

    //PRE:  None
    //POST: Returns a Pointer to the current room
    room * getCurr() {return currentRoom;};

    //PRE:  None
    //POST: Asks user to choose an adjacent room to enter
    //      Calls Combat(), and returns resulting bool
    bool moveNextRoom();

    //PRE:  None
    //POST: Prints Header information for combat sequence
    //      This didn't need to be a template, but project specs required one, so...
    template <typename T, typename U>
        void printCombatHeader(T, T, U);

private:
    int health;
    int treasure;
    int monstersKilled;
    weapon myWeapon;
    room * currentRoom;
};


#endif // PLAYER_H_INCLUDED
