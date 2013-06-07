/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename: functions.h
Purpose:
*/

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "player.h"

namespace functions
{
    void greeting();

    void sleepFunc(unsigned int);
    void clearScreen();
    void gameOver(player);
    int getSafeInt();


    bool mainMenu();

    void gameLoop();
}

#endif // FUNCTIONS_H_INCLUDED
