/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename: room.h
Purpose:
*/

#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <string>
#include "monster.h"

class room
{
public:
    room();

    const bool hasMonster() { return monsterAlive; };

    void setName(std::string);
    void killMonster() {monsterAlive = false;};

    const int getTreasure();
    const monster getMonster() { return randMonster; };
    const std::string getName() { return name; };

    void displayDoors();
    int chooseAdjacentRoom();

    friend std::ostream& operator << (std::ostream &, const room&);

    void setNorth(room* r) { door_NORTH = r; };
    void setSouth(room* r) { door_SOUTH = r; };
    void setEast(room* r) { door_EAST = r; };
    void setWest(room* r) { door_WEST = r; };

    room* getNorth() { return door_NORTH; };
    room* getSouth() { return door_SOUTH; };
    room* getEast() { return door_EAST; };
    room* getWest() { return door_WEST; };

private:
    std::string name;
    int treasure;

    monster randMonster;
    bool monsterAlive;

    room * door_NORTH;
    room * door_EAST;
    room * door_SOUTH;
    room * door_WEST;
};

#endif // ROOM_H_INCLUDED
