
#include "game.h"
#include "input.h"
#include "action.h"
#include "controllers/space.h"

static int P1, P2;

static void keypress(int key) {

}
static void keyrelease(int key) {
    
}
static void keyhold(int key) {
    switch (key) {
        case P1_MARU:
            break;
        case P1_BATSU:
            break;
        case P1_PAUSE:
            break;
        case P1_UP:
            Action_add(ACTION_MOVEFWD, P1);
            break;
        case P1_DOWN:
            break;
        case P1_LEFT:
            Action_add(ACTION_TURNLFT, P1);
            break;
        case P1_RIGHT:
            Action_add(ACTION_TURNRGT, P1);
            break;
        case P2_MARU:
            break;
        case P2_BATSU:
            break;
        case P2_PAUSE:
            break;
        case P2_UP:
            Action_add(ACTION_MOVEFWD, P2);
            break;
        case P2_DOWN:
            break;
        case P2_LEFT:
            Action_add(ACTION_TURNLFT, P2);
            break;
        case P2_RIGHT:
            Action_add(ACTION_TURNRGT, P2);
            break;
        default:
            break;
    }
}

void SpaceController_load() {
    P1 = Game_getPlayer1();
    P2 = Game_getPlayer2();
    Input_registerPress(keypress);
    Input_registerRelease(keyrelease);
    Input_registerHold(keyhold);
}