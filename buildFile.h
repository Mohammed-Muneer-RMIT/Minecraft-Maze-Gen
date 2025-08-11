#ifndef LOC_BUILDER
#define LOC_BUILDER
class Loc_Builder {
    public:
    //constructors/de-constructors
    Loc_Builder();
    Loc_Builder(int length, int width);
    // ~Loc_Builder();
    //methods
    void setMazeSize(int, int);
    int getLength();
    int getWidth();
    void setLocElement(char**);
    void setTerrain(int**);
    void setTerrainBlock(int**);
    void setTopTerrain(int***);
    void setTopTerrainBlock(int***);
    char getLocElement(int, int);
    char** getLocStructure();
    int** getTerrain();
    int** getTerrainBlock();
    int*** getTopTerrain();
    int*** getTopTerrainBlock();
    void setCoordinates(int, int, int);
    int getX_Coord();
    int getY_Coord();
    int getZ_Coord();

    // void playerSolvePos(int, int, int);
    // int getPlayer_X();
    // int getPlayer_Y();
    // int getPlayer_Z();
    

    private:
    //Fields
    int length;
    int width;
    char **locStructure;
    int **terrain_Height;
    int **terrain_Block;
    int ***topTerrain_Height;
    int ***topTerrain_Block;
    int xCoord;
    int yCoord;
    int zCoord;
    // int player_X;
    // int player_Y;
    // int player_Z;


};
#endif //LOC_BUILDER