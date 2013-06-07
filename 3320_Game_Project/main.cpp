/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename:  main.cpp
Purpose:  Adventure Game Project
*/

#include <iostream>
#include <cstdlib>

#include "functions.h"
#include "player.h"
#include "weapon.h"
#include "room.h"


int main()
{
    functions::greeting();

    while(functions::mainMenu())
        functions::gameLoop();

    return EXIT_SUCCESS;
}
