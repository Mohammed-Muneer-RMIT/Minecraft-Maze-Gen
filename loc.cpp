#include "loc.h"

Loc::Loc(){
    this->xCoord = 0;
    this->yCoord = 0;
    this->zCoord = 0;
    this->length = 0;
    this->width = 0;
    // this->player_X = 0;
    // this->player_Y = 0;
    // this->player_Z = 0;
    locStructure = new char*[length];
    for(int i =0; i < length; i++){
        locStructure[i] = new char[width];
    }
}
Loc::Loc(int length, int width) {
    this->length = length;
    this->width = width;
    locStructure = new char*[length];
    for(int i =0; i < length; i++){
        locStructure[i] = new char[width];
    }
}
Loc::~Loc(){
    for(int i=0; i < this->length; i++){
        delete[] this->locStructure[i];
    }
    delete[] this->locStructure;
}

void Loc::setMazeSize(int length, int width) {
    this->length = length;
    this->width = width;
}
int Loc::getLength() {
    return this->length;
}
int Loc::getWidth() {
    return this->width;
}
void Loc::setLocElement(char** locStructure){
    this->locStructure = locStructure;
}

void Loc::setTerrain(int** terrain_Height){
    this->terrain_Height = terrain_Height;
}

void Loc::setTerrainBlock(int** terrain_Block){
    this->terrain_Block = terrain_Block;
}

void Loc::setTopTerrain(int*** terrain_Height){
    this->topTerrain_Height = terrain_Height;
}

void Loc::setTopTerrainBlock(int*** terrain_Block){
    this->topTerrain_Block = terrain_Block;
}

char** Loc::getLocStructure(){
    return this->locStructure;
}

int** Loc::getTerrain(){
    return this->terrain_Height;
}

int** Loc::getTerrainBlock(){
    return this->terrain_Block;
}

int*** Loc::getTopTerrain(){
    return this->topTerrain_Height;
}

int*** Loc::getTopTerrainBlock(){
    return this->topTerrain_Block;
}

char Loc::getLocElement(int row, int col){
    return this->locStructure[row][col];
}
void Loc::setCoordinates(int xCoord, int yCoord, int zCoord){
    this->xCoord = xCoord;
    this->yCoord = yCoord;
    this->zCoord = zCoord;
}

// void Loc::playerSolvePos(int player_X, int player_Y, int player_Z){
//     this->player_X = player_X;
//     this->player_Y = player_Y;
//     this->player_Z = player_Z;
// }

int Loc::getX_Coord(){
    return this->xCoord;
}
int Loc::getY_Coord(){
    return this->yCoord;
}
int Loc::getZ_Coord(){
    return this->zCoord;
}

// int Loc::getPlayer_X(){
//     return this->player_X;
// }
// int Loc::getPlayer_Y(){
//     return this->player_Y;
// }
// int Loc::getPlayer_Z(){
//     return this->player_Z;
// }
