#include "buildFile.h"

Loc_Builder::Loc_Builder(){
    this->xCoord = 0;
    this->yCoord = 0;
    this->zCoord = 0;
    this->length = 0;
    this->width = 0;

    locStructure = new char*[length];
    for(int i =0; i < length; i++){
        locStructure[i] = new char[width];
    }
}
Loc_Builder::Loc_Builder(int length, int width) {
    this->length = length;
    this->width = width;
    locStructure = new char*[length];
    for(int i =0; i < length; i++){
        locStructure[i] = new char[width];
    }
}


void Loc_Builder::setMazeSize(int length, int width) {
    this->length = length;
    this->width = width;
}
int Loc_Builder::getLength() {
    return this->length;
}
int Loc_Builder::getWidth() {
    return this->width;
}
void Loc_Builder::setLocElement(char** locStructure){
    this->locStructure = locStructure;
}

void Loc_Builder::setTerrain(int** terrain_Height){
    this->terrain_Height = terrain_Height;
}

void Loc_Builder::setTerrainBlock(int** terrain_Block){
    this->terrain_Block = terrain_Block;
}

void Loc_Builder::setTopTerrain(int*** terrain_Height){
    this->topTerrain_Height = terrain_Height;
}

void Loc_Builder::setTopTerrainBlock(int*** terrain_Block){
    this->topTerrain_Block = terrain_Block;
}

char** Loc_Builder::getLocStructure(){
    return this->locStructure;
}

int** Loc_Builder::getTerrain(){
    return this->terrain_Height;
}

int** Loc_Builder::getTerrainBlock(){
    return this->terrain_Block;
}

int*** Loc_Builder::getTopTerrain(){
    return this->topTerrain_Height;
}

int*** Loc_Builder::getTopTerrainBlock(){
    return this->topTerrain_Block;
}

char Loc_Builder::getLocElement(int row, int col){
    return this->locStructure[row][col];
}
void Loc_Builder::setCoordinates(int xCoord, int yCoord, int zCoord){
    this->xCoord = xCoord;
    this->yCoord = yCoord;
    this->zCoord = zCoord;
}


int Loc_Builder::getX_Coord(){
    return this->xCoord;
}
int Loc_Builder::getY_Coord(){
    return this->yCoord;
}
int Loc_Builder::getZ_Coord(){
    return this->zCoord;
}


