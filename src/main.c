#include <SDL2/SDL.h>

#include "wm.h"

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("LitePM Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH * 2, HEIGHT * 2, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    //SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);

    SDL_ShowCursor(SDL_DISABLE);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    WM wm;
    WM_CreateWM(&wm);

    for (int running = 1; running;) {
        for (SDL_Event event; SDL_PollEvent(&event);) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) 
                        running = 0;
                    break;
                case SDL_QUIT:
                    running = 0;
                    break;
            }

            //wm_handle_event(&event);
        }

        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderClear(renderer);

        //wm_draw(renderer);

        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, mouse_x - 10, mouse_y, mouse_x + 10, mouse_y);
        SDL_RenderDrawLine(renderer, mouse_x, mouse_y - 10, mouse_x, mouse_y + 10);

        SDL_RenderPresent(renderer);
        SDL_Delay(33); // ~30 FPS
    }

    WM_DestroyWM(&wm);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}
