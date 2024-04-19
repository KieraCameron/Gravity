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

const int width = 800;
const int height = 600;
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


int main(int argc, char* argv[])
{
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window *window = SDL_CreateWindow("Gravity", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    
    // pause_window();
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    bool running = true;
    SDL_Event e;
    

//    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
//    SDL_Rect rect = {50, 50, 200, 200};
//    SDL_RenderFillRect(renderer, &rect);
//    
//    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//    SDL_Rect rect2 = {300, 50, 200, 200};
//    SDL_RenderDrawRect(renderer, &rect2);
    
    
    int dx = 0;
    int dy = 0;
    const int vx = -1;
    const int vy = -1;
    time_t start = time(NULL);
    double dur;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_Rect rect = {width - 50 + dx, height - 50 + dy, 50, 50};
        SDL_RenderDrawRect(renderer, &rect);
        

        SDL_RenderPresent(renderer);
        dur = difftime(time(NULL), start);
        printf("%f\n", dur);
        dx = vx * dur;
        dy = vy * dur;


    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
