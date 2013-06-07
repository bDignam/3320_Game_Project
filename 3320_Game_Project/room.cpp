/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename: room.cpp
Purpose:
*/

#include "room.h"
#include "functions.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iterator>

room::room()
{
    name = "";
    treasure = 100; //Max Treasure value

    //Initialize Monster
    monsterAlive = true;
    monster randMonster;    //Randomize!

    door_NORTH = NULL;
    door_EAST = NULL;
    door_SOUTH = NULL;
    door_WEST = NULL;
}

void room::setName(std::string newName)
{
    name = newName;
}

void room::displayDoors()
{
    std::cout << "\nCurrent Room:  " << getName() << "\n";

    std::cout << "Adjacent Rooms:\n\n";
    if(door_NORTH != NULL)
        std::cout << "[1]  [NORTH]  " << door_NORTH->name << "\n";
    else
        std::cout << '\n';
    if(door_EAST != NULL)
        std::cout << "[2]  [EAST]   " << door_EAST->name << "\n";
    else
        std::cout << '\n';
    if(door_SOUTH != NULL)
        std::cout << "[3]  [SOUTH]  " << door_SOUTH->name << "\n";
    else
        std::cout << '\n';
    if(door_WEST != NULL)
        std::cout << "[4]  [WEST]   " << door_WEST->name << "\n";
    else
        std::cout << '\n';
    std::cout << "\n>";
}

int room::chooseAdjacentRoom()
{
    room::displayDoors();               //Displays list of valid doors

    std::vector<int> validDoorNums;     //Vector of valid door directions
    if(door_NORTH != NULL)              //  1=NORTH, 2=EAST, etc
        validDoorNums.push_back(1);
    if(door_EAST != NULL)
        validDoorNums.push_back(2);
    if(door_SOUTH != NULL)
        validDoorNums.push_back(3);
    if(door_WEST != NULL)
        validDoorNums.push_back(4);

    int choice = functions::getSafeInt();

    std::vector<int>::iterator iter;
    while (true)        //Keeps asking for int until choice is found in vector
    {
        iter = validDoorNums.begin();
        while( iter != validDoorNums.end() )
        {
            if ( choice == *iter )  //If choice is a valid choice
                return choice;
            else
                iter++;
        }
        std::cout << "\nPlease enter a valid door number [1, 2, 3, 4]\n";
        std::cout << ">";
        choice = functions::getSafeInt();
    }

    //Uncomment this to choose room RANDOMLY
    //    srand (time(NULL));
    //    int randInt = rand()%(validDoorNums.size());    //Randomly chooses from door vector
    //
    //    return validDoorNums[randInt];                //Returns direction valid door is in
    //                                                    //  1=NORTH, 2=EAST, etc
}

const int room::getTreasure()
{
    srand (time(NULL));
    return rand()%treasure;         //returns random amount of Treasure
}

std::ostream& operator << (std::ostream& out, const room& tempRoom)
{
    out << tempRoom.name;
    return out;
}
