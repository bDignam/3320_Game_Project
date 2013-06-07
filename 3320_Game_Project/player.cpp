/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename: player.cpp
Purpose:
*/

#include "player.h"
#include "functions.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

player::player()
{
    health = 50;
    treasure = 0;
    monstersKilled = 0;
    currentRoom = NULL;

    srand (time(NULL));
    int randInt = rand()%2;

    //Random Player Weapon
    if(randInt == 0)
        myWeapon = weapon("Sword", 0.4, 5);
    else if(randInt == 1)
        myWeapon = weapon("Axe", 0.5, 4);
    else
        myWeapon = weapon("Spear", 0.6, 3);
}


void player::print_Score_Screen()
{
    std::cout << std::left;
    std::cout << "PLAYER STATS\n\n";

    std::cout << std::setw(17) << "Health:  " << getHealth() << "\n";
    std::cout << std::setw(17) << "Treasure:  " << getTreasure() << "\n";
    std::cout << std::setw(17) << "Weapon Name:  " << getWeaponName() << "\n";
    std::cout << std::setw(17) << "Monsters Killed: " << getMonstersKilled() << "\n";
}

bool player::combat()
{
    if (currentRoom->hasMonster())
    {
        //FIGHT!
        functions::clearScreen();

        //Copy monster by reference
        monster mon(currentRoom->getMonster());

        while ( true )      //Breaks by returning a bool when either monster or player dies
        {
            int dmg(0);

            //Player hits Monster
            dmg = strike();
            mon.takeDamage( dmg );

            //Combat Header
            player::printCombatHeader<int, std::string>(getHealth(), mon.getHealth(), mon.getName());

            //Displays damage done on either side
            if( dmg > 0)
                std::cerr << std::right << std::setw(44) << "Hit!    -" << dmg;
            else
                std::cerr << std::right << std::setw(44) << "Miss!";

            std::cout << "\n\n\n\n";
            currentRoom->displayDoors();

            //Wait
            //sleepFunc(1200);  //Didn't work on Linux, so Busy-Wait...
            for(int i(0); i < 220000000; i++)
            { }

            if (mon.getHealth() < 1)    //Monster Death Check
            {
                //VICTORY
                monstersKilled++;
                currentRoom->killMonster();
                addTreasure(currentRoom->getTreasure());

                functions::clearScreen();
                std::cout << "Victory!\n\n";
                print_Score_Screen();
                std::cout << "\n";
                return true;
            }

            //Monster hits Player
            dmg = mon.strike();
            takeDamage( dmg );

            //Combat Header
            player::printCombatHeader<int, std::string>(getHealth(), mon.getHealth(), mon.getName());

            //Displays damage done on either side
            if( dmg > 0)
                std::cerr << "Hit!    -" << dmg;
            else
                std::cerr << "Miss!";

            std::cout << "\n\n\n\n";
            currentRoom->displayDoors();

            //Wait
            //sleepFunc(1200);  //Didn't work on Linux, so Busy-Wait...
            for(int i(0); i < 220000000; i++)
            { }

            if (getHealth() < 1)    //Player Death Check
            {
                return false;       //DEAD!
            }

        }
    }
    else
    {
        //No Monster
        functions::clearScreen();
        std::cerr << "\nRoom Clear:  No Monster\n\n\n\n\n";
    }
}

bool player::moveNextRoom()
{
    int choice;
    choice = currentRoom->chooseAdjacentRoom();     //Picks a random valid door

    if(choice == 1)
        setCurrentRoom(currentRoom->getNorth());
    if(choice == 2)
        setCurrentRoom(currentRoom->getEast());
    if(choice == 3)
        setCurrentRoom(currentRoom->getSouth());
    if(choice == 4)
        setCurrentRoom(currentRoom->getWest());

    return combat();        //combat() only returns false if player dies
}

void player::takeDamage(int dmg)
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

template <typename T, typename U>
    void player::printCombatHeader(T pHealth, T mHealth, U mName)
{
    functions::clearScreen();
    std::cout << std::left << std::setw(35) << "Player" << mName << "\n";
    std::cout << std::left << "Player Health: " << std::setw(20) << pHealth;
    std::cout << "Monster Health: " << mHealth;
    std::cout << "\n\n";
}

void player::sleepFunc( unsigned int timeToWait )
{
    clock_t wait_nanoseconds = (clock_t) timeToWait;
    clock_t start_time = clock();
    while( clock() != start_time + wait_nanoseconds );
    return;
}
