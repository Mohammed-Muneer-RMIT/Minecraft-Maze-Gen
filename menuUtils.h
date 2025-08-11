#ifndef MENU_UTILS_H
#define MENU_UTILS_H

#include <iostream>
#include "Maze.h"

void printStartText(void){

    std::cout << std::endl;
    std::cout << "Welcome to MineCraft MazeRunner!" << std::endl;
    std::cout << "--------------------------------" << std::endl;

}

void printMainMenu(void){

    std::cout << std::endl;
    std::cout << "------------- MAIN MENU -------------" << std::endl;
    std::cout << "1) Generate Maze" << std::endl;
    std::cout << "2) Build Maze in MineCraft" << std::endl;
    std::cout << "3) Solve Maze" << std::endl;
    std::cout << "4) Show Team Information" << std::endl;
    std::cout << "5) Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter Menu item to continue: " << std::endl;

}

void printGenerateMazeMenu(void){

    std::cout << std::endl;
    std::cout << "------------- GENERATE MAZE -------------" << std::endl;
    std::cout << "1) Read Maze from terminal" << std::endl;
    std::cout << "2) Generate Random Maze" << std::endl;
    std::cout << "3) Back" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter Menu item to continue: " << std::endl;

}

void printSolveMazeMenu(void){

    std::cout << std::endl;
    std::cout << "------------- SOLVE MAZE -------------" << std::endl;
    std::cout << "1) Solve Manually" << std::endl;
    std::cout << "2) Show Escape Route" << std::endl;
    std::cout << "3) Back" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter Menu item to continue: " << std::endl;

}


void printTeamInfo(void){

    std::cout << std::endl;
    std::cout << "Team members:" << std::endl;
    std::cout << "\t [1] Mohammed Muneer Abdul Sathar(s4029181@student.rmit.edu.au)" << std::endl;
    std::cout << "\t [2] Saaivignesh Sayanthan (s4027572@student.rmit.edu)" << std::endl;
    std::cout << "\t [3] Febin Hafiz (s4052842@student.rmit.edu)" << std::endl;
    std::cout << std::endl;

}

void printExitMassage(void){


    std::cout << std::endl;
    std::cout << "The End!" << std::endl;
    std::cout << std::endl;


}

void printMainInputError(void){

    std::cout << "Input Error: Enter a number between 1 and 5 ...." << std::endl;
}

void printMinInputError(void){

    std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
}


char getOptionInput(void){
    
std::string stringInput; //we initially get input into a string instead of char to check inputvalidity.
char charInput;          

std::cin >> stringInput;
if(stringInput.length() != 1){
    charInput = '`';
}
else{
    charInput = stringInput[0];
}
return charInput;
}

#endif //MENU_UTILS_H
