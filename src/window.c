
#include "debug.h"
#include "game.h"
#include "window.h"

#include <SDL.h>
#include <SDL.h>
#include <stdio.h>
#include "utility/bool.h"

struct _window {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

static Window WINDOW;

void Window_init() {
    WINDOW.window = SDL_CreateWindow( "Space Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
    if (WINDOW.window == NULL) {
        logprint( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        Game_quit();
    }

    WINDOW.renderer = SDL_CreateRenderer(WINDOW.window, -1, SDL_RENDERER_ACCELERATED);
    if (WINDOW.renderer == NULL) {
        logprint( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        Game_quit();
    }

    SDL_SetRenderDrawColor( WINDOW.renderer, 0x00, 0x00, 0x00, 0xFF );
    logprint("SDL and its components initialized. Window initialized.\n");
}

SDL_Renderer* Window_getRenderer() {
    return WINDOW.renderer;
}

void Window_update() {
    SDL_RenderPresent( WINDOW.renderer );
}

void Window_close() {
    SDL_DestroyRenderer(WINDOW.renderer);
    SDL_DestroyWindow(WINDOW.window);

    WINDOW.renderer = NULL;
    WINDOW.window = NULL;
}
