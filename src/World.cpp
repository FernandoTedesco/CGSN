#include "World.h"
#include <cstdlib>

World::World(int w, int h)
{
    width = w;
    height = h;
    grid.resize(width * height);
}

int World::getIndex(int x, int y)const
{
    return x+(y*width);
}

Cell& World::getCell(int x, int y)
{
    if(x<0||x>=width||y<0||y>=height)
    {
        static Cell outOfBounds = {WALL, 0,0,0,0,0};
        return outOfBounds;

    }
    return grid[getIndex(x,y)];
}

void World::setCell(int x, int y, CellType type)
{
    if(x<0||x>=width||y<0|| y>= height)return;
    int index = getIndex(x,y);
    grid[index].type = type;

    switch(type)
    {
        case EMPTY: grid[index].r = 0;grid[index].g = 0; grid[index].b =0;
        break;
        case WALL: grid[index].r = 100; grid[index].g = 100; grid[index].b = 100;
        break;
        case WATER: grid[index].r = 0; grid[index].g = 0; grid[index].b = 255;
        break;
        case FOOD: grid[index].r = 0; grid[index].g = 255; grid[index].b = 0;
        break;
    }
}

void World::generate()
{
    for(int y =0; y<height; y++)
    {
        for(int x = 0; x<width; x++)
        {
            if(x == 0|| x == width-1|| y ==0 || y == height - 1)
            {
                setCell(x,y,WALL);

            }
            else
            {
                setCell(x,y,EMPTY);
            }
        }
    }
}