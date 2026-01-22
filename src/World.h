#pragma once
#include <vector>
#include <cstdint>

enum CellType : uint8_t{
    EMPTY = 0,
    WATER = 1,
    WALL = 2,
    FOOD = 3
};

struct Cell{
    uint8_t type; //Type of map cell
    float signal; //Invis value for agents to find each other (TBD)
    float density; //how much food/water
    uint8_t r,g,b;// cell color
};

class World{
    public:
    int width, height;
    std::vector<Cell> grid;
    World(int w, int h);
    int getIndex(int x, int y) const;

    Cell& getCell(int x, int y);
    void setCell(int x, int y, CellType type);

    void generate();
};