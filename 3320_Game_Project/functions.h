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

    //PRE:  None
    //POST: Greets user
    void greeting();

    //PRE:  NOT run on Linux
    //POST: Sleeps for int milliseconds
    void sleepFunc(unsigned int);

    //PRE:  None
    //POST: Prints 40 new lines
    void clearScreen();

    //PRE:  Player has been initialized
    //POST: Prints Game Over message & Player Stats
    void gameOver(player);

    //PRE:  None
    //POST: Gets integer from Player
    int getSafeInt();

    //PRE:  None
    //POST: Returns True until user chooses to Quit
    bool mainMenu();

    //PRE:  None
    //POST: Initializes game values, runs until GAME OVER
    void gameLoop();
}

#endif // FUNCTIONS_H_INCLUDED
