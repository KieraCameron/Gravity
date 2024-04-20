//
//  main.c
//  Gravity
//
//  Created by Yusuf Jaafar on 14/04/2024.
//

// first, compile the main.c programme
// cc -o main main.c -F /Library/Frameworks -framework SDL2
// then set the environment variable
// export dyld_framework_path=/Library/Frameworks/
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "utils.h"
#include <time.h>

const int WIDTH = 800;
const int HEIGHT = 600;
void pause_window(void)
{
    SDL_Event e;
    bool running = true;
    while (running){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                running = false;
            }
        }
    }
}

void move_rect(SDL_Rect *rect, int *dirx, int *diry, int speed)
{
    //SDL_Delay(1000/speed);
    rect->x += 1 * (*dirx);
    rect->y += 1 * (*diry);
    if (rect->x == 0 || rect->x == WIDTH - rect->w) {
        (*dirx) *= -1;
    }
    if (rect->y == 0 || rect->y == HEIGHT - rect->h) {
        (*diry) *= -1;
    }
}

int main(int argc, char* argv[])
{
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window *window = SDL_CreateWindow("Gravity", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    
    // pause_window();
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    bool running = true;
    SDL_Event e;
        
    
    int dirx = -1;
    int diry = -1;
    int sx = 1000;
    int sy = 800;
    int speed = sqrt(sx*sx + sy*sy);
    SDL_Rect rect = {WIDTH - 50, HEIGHT - 50, 50, 50};
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        move_rect(&rect, &dirx, &diry, speed);
        SDL_RenderFillRect(renderer, &rect);
        

        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
