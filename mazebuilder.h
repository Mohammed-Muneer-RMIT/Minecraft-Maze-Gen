#ifndef MAZEBUILDER
#define MAZEBUILDER

#include "loc.h"
#include "buildFile.h"
#include "restore.h"
#include <iostream>




bool doesMazeExist(int build_x, int build_y , int build_z , int Maze_Length, int Maze_Width, char**& Maze_Structure, mcpp::MinecraftConnection& mc) {

bool mazeExists = false;
    for (int x = build_x ; x < build_x + Maze_Length && !mazeExists; x++) {
        for (int z = build_z ; z < build_z + Maze_Width && !mazeExists; z++) {
            for (int y = build_y; y < build_y + 3; y++) {
                mcpp::BlockType blockType = mc.getBlock(mcpp::Coordinate(x, y, z));

                if (blockType == mcpp::Blocks::ACACIA_WOOD_PLANK) {
                    mazeExists = true;
                }
            }
        }
    }

    return mazeExists;
}

void flattenTerrain(int build_x, int build_y , int build_z , int Maze_Length, int Maze_Width, mcpp::MinecraftConnection& mc, int**& Terrain_Structure, int**& Terrain_BlockType, int***& topStructure, int***& topBlockType) {
    int newHeight = 0;
    
    for (int x = build_x; x < build_x + Maze_Length; x++) {
        for (int z = build_z ; z < build_z + Maze_Width; z++) {
                    
            newHeight = mc.getHeight(x, z);
            if(newHeight >= build_y){
                for (int y = build_y; y <= newHeight; y++) {
                    topStructure[y - build_y][x - build_x][z - build_z] = y;
                    int topBlock = mc.getBlock(mcpp::Coordinate(x, y, z)).id;
                    topBlockType[y - build_y][x - build_x][z - build_z] = topBlock;
            
                    mc.setBlock(mcpp::Coordinate(x, y, z), mcpp::Blocks::AIR);
                }
            }
            
            newHeight = mc.getHeight(x, z);
            Terrain_Structure[x - build_x][z - build_z] = newHeight;
            int blockType = mc.getBlock(mcpp::Coordinate(x, newHeight, z)).id;
            Terrain_BlockType[x - build_x][z - build_z] = blockType;
            if(newHeight < build_y){
                for (int y = newHeight; y <= build_y - 1; y++) {
                
                    mc.setBlock(mcpp::Coordinate(x, y, z), blockType);
                }
            }
                
        }
    }
}



void teleportPlayer(int build_x, int build_y , int build_z , mcpp::MinecraftConnection& mc) {
    int newY = build_y + 10;
    mc.setPlayerPosition(mcpp::Coordinate(build_x, newY, build_z));
}

void buildWalls(int build_x, int build_y , int build_z , int Maze_Length, int Maze_Width, char** Maze_Structure , mcpp::MinecraftConnection& mc, int exitX, int exitZ) {
    for (int x = 0; x < Maze_Length; x++) {
        for (int z = 0; z < Maze_Width; z++) {
            if (Maze_Structure[x][z] == 'x') {
                for (int y = 0; y < 3; y++) {
                    mc.setBlock(mcpp::Coordinate(build_x + x, build_y + y, build_z + z), mcpp::Blocks::ACACIA_WOOD_PLANK);
                }
            }
            else if(Maze_Structure[x][z] == '.'){
                for (int y = 0; y < 3; y++) {
                    mc.setBlock(mcpp::Coordinate(build_x + x, build_y + y, build_z + z), mcpp::Blocks::AIR);
                }
            }
        }
    }
    std::cout << "(" << exitX << " , "<<exitZ<< ")" << std::endl;
    mc.setBlock(mcpp::Coordinate(exitX, build_y, exitZ), mcpp::Blocks::BLUE_CARPET);
}

void mazeMaker(Loc& loc, mcpp::MinecraftConnection& mc, Loc_Builder& loc_Builder, Maze& maze) {
    int xCoord = loc.getX_Coord(); 
    int yCoord = loc.getY_Coord();
    int zCoord = loc.getZ_Coord();
    int x_len = loc.getLength();
    int z_len = loc.getWidth();
    char **Maze_Structure = loc.getLocStructure();

    int exitX = maze.getExitX();
    int exitZ = maze.getExitZ();

    int **Terrain_Structure;
    Terrain_Structure = new int*[x_len];
    for(int i=0; i < x_len; i++){
        Terrain_Structure[i] = new int[z_len];
    }

    int **Terrain_BlockType;
    Terrain_BlockType = new int*[x_len];
    for(int i=0; i < x_len; i++){
        Terrain_BlockType[i] = new int[z_len];
    }

    int ***topStructure;
    topStructure = new int**[100];
    for(int i=0; i < 100; i++){
        topStructure[i] = new int*[x_len];
        for(int j=0; j < x_len; j++){
            topStructure[i][j] = new int[z_len];
        }
    }

    int ***topBlockType;
    topBlockType = new int**[100];
    for(int i=0; i < 100; i++){
        topBlockType[i] = new int*[x_len];
        for(int j=0; j < x_len; j++){
            topBlockType[i][j] = new int[z_len];
        }
    }


    bool mazeChecker = doesMazeExist(xCoord, yCoord , zCoord, x_len, z_len, Maze_Structure, mc);
    
    if (mazeChecker)
    {
        clearMaze(loc_Builder.getX_Coord(), loc_Builder.getY_Coord(), loc_Builder.getZ_Coord(), loc_Builder.getLength(), loc_Builder.getWidth(), mc);
        unFlattenTerrain(loc_Builder.getX_Coord(), loc_Builder.getY_Coord() , loc_Builder.getZ_Coord() , loc_Builder.getLength(), loc_Builder.getWidth(), mc, loc_Builder.getTerrain(), loc_Builder.getTerrainBlock(),loc_Builder.getTopTerrain(), loc_Builder.getTopTerrainBlock());

    }

    teleportPlayer(xCoord, yCoord , zCoord, mc);
    flattenTerrain(xCoord, yCoord , zCoord, x_len, z_len, mc, Terrain_Structure, Terrain_BlockType, topStructure, topBlockType);
    loc.setTerrain(Terrain_Structure);
    loc.setTerrainBlock(Terrain_BlockType);
    loc.setTopTerrain(topStructure);
    loc.setTopTerrainBlock(topBlockType);
    buildWalls(xCoord, yCoord , zCoord, x_len, z_len, Maze_Structure, mc, exitX, exitZ);
    loc_Builder.setCoordinates(xCoord, yCoord, zCoord);
    loc_Builder.setMazeSize(loc.getLength(), loc.getWidth());
    loc_Builder.setLocElement(Maze_Structure);
    loc_Builder.setTerrain(Terrain_Structure);
    loc_Builder.setTerrainBlock(Terrain_BlockType);
    loc_Builder.setTopTerrain(topStructure);
    loc_Builder.setTopTerrainBlock(topBlockType);

}

#endif //MAZEBUILDER