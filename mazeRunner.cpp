#include <iostream>
#include <mcpp/mcpp.h>

#include "menuUtils.h"
#include "mazebuilder.h"
#include "Maze.h"
#include "Agent.h"
#include "loc.h"
#include "restore.h"
#include "buildFile.h"


#include <vector>
#include <random>

#define NORMAL_MODE 0
#define TESTING_MODE 1
    
enum States{
    ST_Main,
    ST_GetMaze,
    ST_BuildMaze,
    ST_SolveMaze,
    ST_Creators,
    ST_Exit
};

int main(int argc, char** argv){
    
    bool mode = NORMAL_MODE;
    mcpp::MinecraftConnection mc; 
    mc.doCommand("time set day");
    printStartText();

    
    



    //-----------------------------------------------------------------------------------------//
    
    Loc loc;
    Loc_Builder loc_Builder;
    Maze maze;
    Agent agent;
    bool mazeBuilt = false;
    bool placed = false;


    //menu states
    //-------------------------------------------------------------------------------------------//
    States curState = ST_Main; 

    while(curState != ST_Exit)
    {
        if(curState == ST_Main)
        {
            while(curState == ST_Main)
            {
                printMainMenu();
                char Get_Menu_Num = getOptionInput();

                if(Get_Menu_Num == '1')
                {
                    curState = ST_GetMaze;
                }
                else if(Get_Menu_Num == '2')
                { 
                    curState = ST_BuildMaze;
                }
                else if(Get_Menu_Num == '3')
                {
                    curState = ST_SolveMaze;
                }
                else if(Get_Menu_Num == '4')
                {
                    curState = ST_Creators;
                }
                else if(Get_Menu_Num == '5')
                {
                    curState = ST_Exit; 
                }
                else
                {
                    printMainInputError();
                }
            }
        }
        else if(curState == ST_GetMaze)
        {
            while(curState == ST_GetMaze)
            {
                printGenerateMazeMenu();
                char Get_Maze_Num = getOptionInput();
                
                if (Get_Maze_Num == '1')
                {
                    maze.readMazeTerminal(loc,mc);
                    curState = ST_Main;
                }
                else if(Get_Maze_Num == '2')
                {
                    maze.makeRandomMaze(loc,mc,mode);
                    curState = ST_Main;
                }
                else if(Get_Maze_Num == '3')
                {
                    curState = ST_Main;
                }
                else 
                {
                    printMinInputError();
                }   
            }
        }
        else if(curState == ST_BuildMaze)
        {
            if(loc.getLength() != 0){
                mazeMaker(loc,mc,loc_Builder,maze);
                mazeBuilt = true;
            }
            else{
                std::cout << "Maze not defined! Generate maze before Building." << std::endl;
            }
            
            curState = ST_Main;
        }
        else if(curState == ST_SolveMaze)
        {
            while(curState == ST_SolveMaze)
            {   
                printSolveMazeMenu();
                char Get_Solve_Num = getOptionInput();

                if (Get_Solve_Num == '1')
                {
                    if(loc_Builder.getLength() != 0){
                    agent.playerPlacer(mc,loc_Builder,mode);
                    placed = true;
                }
                else{
                    std::cout << "Generate and build a maze first." << std::endl;
                }
                }
                else if(Get_Solve_Num == '2')
                {
                    placed = true;      //testing purposes;
                    if(placed){
                        agent.mazeSolver(mc);
                    }
                    else{
                        std::cout << "Initialize player using Solve manually." << std::endl;
                    }
                }
                else if(Get_Solve_Num == '3')
                {
                    curState = ST_Main;
                } 
                else 
                {
                    printMinInputError();
                }
            }
        }
        else if(curState == ST_Creators)
        {
            printTeamInfo();
            curState = ST_Main;
        }
    }

    //---------------------------------------------------------------------------------------------------//
    if(loc.getLength() != 0 && mazeBuilt){
        clearMaze(loc_Builder.getX_Coord(), loc_Builder.getY_Coord(), loc_Builder.getZ_Coord(), loc_Builder.getLength(), loc_Builder.getWidth(), mc);
        unFlattenTerrain(loc_Builder.getX_Coord(), loc_Builder.getY_Coord() , loc_Builder.getZ_Coord() , loc_Builder.getLength(), loc_Builder.getWidth(), mc, loc_Builder.getTerrain(), loc_Builder.getTerrainBlock(),loc_Builder.getTopTerrain(), loc_Builder.getTopTerrainBlock());
    }

    printExitMassage();

    return EXIT_SUCCESS;
}
