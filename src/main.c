
#include "debug.h"
#include "game.h"
#include "config/time.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "utility/bool.h"

static bool init_libs() {
    do {
        if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
            logprint( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
            break;
        }
        if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) ) {
            logprint( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            break;
        }
        if( TTF_Init() == -1 ) {
            logprint( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
            break;
        }
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) == -1 ) {
            break;
        }
        return false;
    } while (0);

    /* ERROR */
    logprint("ERROR: SDL was not initialized. Program shutting down.\n");
    return true;
}

static void close_libs() {
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* const argv[]) {
    bool quit = init_libs();

    logprint("RUNNING GAME IN DEBUG MODE, SOME LAGGING MAY OCCUR.\n");

    /* Inicializa programa. */
    Game_init( argv[0] );

    while (!quit) {
        quit = Game_update();                   /* Main game loop */
        SDL_Delay( Time_getFramemilisec() );    /* FPS delay */
    }

    /* Encerra programa. */
    Game_close();
    close_libs();

    return 0;
}
