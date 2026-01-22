#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("CGSN Runtime", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    if(!window)return -1;
    
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
        SDL_Delay(16);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}