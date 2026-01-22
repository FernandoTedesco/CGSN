#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <vector>
#include "World.h"

const int SIM_WIDTH = 320;
const int SIM_HEIGHT = 180;
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

void render_world(const World& world, std::vector<uint32_t>& buffer)
{
    int total_cells = world.width * world.height;
    for(int i = 0; i< total_cells; i++)
    {
        const Cell& cell = world.grid[i];
        uint32_t color = (255<<24)|(cell.r<<16)|(cell.g<<8)|cell.b;

        buffer[i] = color;
    }
}

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("CGSN Runtime", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    if(!window)return -1;

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SIM_WIDTH, SIM_HEIGHT);

    World world(SIM_WIDTH, SIM_HEIGHT);
    world.generate();
    std::vector<uint32_t> pixelBuffer(SIM_WIDTH * SIM_HEIGHT);
    bool isRunning = true;
    SDL_Event event;
    
    while(isRunning){
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                isRunning = false;
            }
        }

        render_world(world,pixelBuffer);
        SDL_UpdateTexture(texture, nullptr, pixelBuffer.data(), SIM_WIDTH* sizeof(uint32_t));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}