/*
Author: Brian Dignam
Date:  4-22-13
Class: CS 3320
Filename: functions.cpp
Purpose:
*/

#include "functions.h"
#include "player.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>

namespace functions
{
    void greeting()
    {
        std::cout << "\n\nWelcome to Adventure Game!\n\n";
    }

    int getSafeInt()
	{
		int x;
		std::string tempString = "";

        std::cin.clear();
		std::getline(std::cin, tempString);

		std::stringstream tempStream(tempString);
		if(tempStream >> x)
			return x;

        return x;
		//throw x;
	}

    void clearScreen()
    {
        std::cout << std::string(40, '\n');
    }

    void gameOver(player Adventurer)
    {
        functions::clearScreen();
        std::cout << "GAME OVER  -  ";
        if ( Adventurer.getHealth() > 0 )
            std::cout << "VICTORY!\n\n";
        else
            std::cout << "DEFEAT!\n\n";
        std::cout << std::left;
        std::cout << "PLAYER STATS:\n\n";
        std::cout << std::setw(17) << "Health:  " << Adventurer.getHealth() << "\n";
        std::cout << std::setw(17) << "Treasure:  " << Adventurer.getTreasure() << "\n";
        std::cout << std::setw(17) << "Weapon Name:  " << Adventurer.getWeaponName() << "\n";
        std::cout << std::setw(17) << "Monsters Killed: " << Adventurer.getMonstersKilled() << "\n";

        std::cout << "\n\nPress Enter to return to MAIN MENU...";
        functions::getSafeInt();
        //Adventurer.print_Score_Screen();


    }

    bool mainMenu()
    {
        bool giveHint = false;
        while(true)
        {
            functions::clearScreen();
            std::cout << "\nMAIN MENU\n\n";
            std::cout << "  1:  Start NEW game\n";
            std::cout << "  2:  Exit\n\n";
            std::cout << "Your selection:   ";
            if (giveHint)
                std::cout << "Please enter a 1 or 2";

            std::cout << "\n>";

            switch(functions::getSafeInt())
            {
                case 1: return true;        //restart game-loop
                case 2: return false;       //Exit
                default: giveHint = true;
            }
        }
    }

    void gameLoop()
    {
        //Initialize rooms
        room roomArray[5];

        enum roomName {GUARD_ROOM, COURTYARD, ART_ROOM, GREAT_HALL, DUNGEON};

        roomArray[GUARD_ROOM].setName("Guard Room");
        roomArray[GUARD_ROOM].setNorth(roomArray+COURTYARD);

        roomArray[COURTYARD].setName("Courtyard");
        roomArray[COURTYARD].setSouth(roomArray+GUARD_ROOM);
        roomArray[COURTYARD].setEast(roomArray+GREAT_HALL);
        roomArray[COURTYARD].setNorth(roomArray+ART_ROOM);

        roomArray[ART_ROOM].setName("Art Room");
        roomArray[ART_ROOM].setSouth(roomArray+COURTYARD);

        roomArray[GREAT_HALL].setName("Great Hall");
        roomArray[GREAT_HALL].setWest(roomArray+COURTYARD);
        roomArray[GREAT_HALL].setSouth(roomArray+DUNGEON);

        roomArray[DUNGEON].setName("Dungeon");
        roomArray[DUNGEON].setNorth(roomArray+GREAT_HALL);

        //Initialize player
        player Adventurer;

        //ACTUAL Game Loop
        Adventurer.setCurrentRoom(roomArray+0);
        Adventurer.combat();

        //Game ends when all 5 monsters dead, or Adventurer dead
        while (Adventurer.getMonstersKilled() < 5 && Adventurer.getHealth() > 0)
        {
            Adventurer.moveNextRoom();
            //Adventurer.print_Score_Screen();
        }

        functions::clearScreen();

        functions::gameOver(Adventurer);


        //Destruct rooms
        //delete [] roomArray;
        //Destruct scoreboard
        //Destruct player
    }

    void sleepFunc( unsigned int timeToWait )
    {
        clock_t wait_nanoseconds = (clock_t) timeToWait;
        clock_t start_time = clock();
        while( clock() != start_time + wait_nanoseconds );
        return;
    }
}
