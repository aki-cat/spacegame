
#include "game.h"
#include "factory.h"
#include "action.h"
#include "config/conf.h"
#include "config/font.h"
#include "components/physics.h"
#include "components/drawpos.h"
#include "components/drawquad.h"
#include "components/sprite.h"
#include "components/textbox.h"
#include "components/timer.h"

#include <stdio.h>
#include <stdlib.h>

/* Load entity from conf */

void Factory_loadPlanet() {
    float m, r, x, y;
    int phys, dquad, dpos, sprite, planet;

    Conf_getPlanetValues(&m, &r, &x, &y);
    phys = Physics_new(m, r, x, y, 0, 0);
    dquad = DrawQuad_new(1408, 128, 128, 128);
    dpos = DrawPos_new(phys, 128, 128, 64, 64);
    sprite = Sprite_new("planetv2.png", dpos, dquad, 1);
    planet = Entity_new(phys, dquad, dpos, sprite, -1);
    Action_add(ACTION_ANIMATE, planet);
    printf("< PLANET ID #%d >\n", planet);
}

void Factory_loadPlayer1() {
    float m, r, x, y, vx, vy;
    int phys, dquad, dpos, sprite, textbox;
    char name[32];

    printf("%s\n", Conf_getString(CONF_SHIP1));
    Conf_getShipValues(0, name, &m, &r, &x, &y, &vx, &vy);
    phys = Physics_new(m, r, x, y, vx, vy);
    dquad = DrawQuad_new(768, 64, 64, 64);
    dpos = DrawPos_new(phys, 64, 64, 32, 32);
    sprite = Sprite_new("cat00.png", dpos, dquad, 1);
    dpos = DrawPos_new(phys, 0, 0, 0, 0);
    textbox = Textbox_new(name, dpos, TEXTALIGN_CENTER, FONTSIZE_SMALL, FONTCOLOR_WHITE);

    Game_setPlayer1( Entity_new(phys, dquad, dpos, sprite, textbox) );
    Action_add(ACTION_GRAVITY, Game_getPlayer1());
    Action_add(ACTION_COLLIDE, Game_getPlayer1());
    printf("< SHIP1 ID #%d >\n", Game_getPlayer1());
}

void Factory_loadPlayer2() {
    float m, r, x, y, vx, vy;
    int phys, dquad, dpos, sprite, textbox;
    char name[32];

    printf("%s\n", Conf_getString(CONF_SHIP2));
    Conf_getShipValues(1, name, &m, &r, &x, &y, &vx, &vy);
    phys = Physics_new(m, r, x, y, vx, vy);
    dquad = DrawQuad_new(768, 64, 64, 64);
    dpos = DrawPos_new(phys, 64, 64, 32, 32);
    sprite = Sprite_new("cat01.png", dpos, dquad, 1);
    dpos = DrawPos_new(phys, 0, 0, 0, 0);
    textbox = Textbox_new(name, dpos, TEXTALIGN_CENTER, FONTSIZE_SMALL, FONTCOLOR_WHITE);
    
    Game_setPlayer2( Entity_new(phys, dquad, dpos, sprite, textbox) );
    Action_add(ACTION_GRAVITY, Game_getPlayer2());
    Action_add(ACTION_COLLIDE, Game_getPlayer2());
    printf("< SHIP2 ID #%d >\n", Game_getPlayer2());
}

void Factory_loadBackground() {
    int dpos, sprite, bg;
    /* Background */
    dpos = DrawPos_new(-1, 800, 600, 400, 300);
    sprite = Sprite_new("background.png", dpos, -1, 0);
    bg = Entity_new(-1, -1, dpos, sprite, -1);
    printf("< BACKGROUND ID #%d >\n", bg);
}


/* New entity from game */

void Factory_newBullet();

void Factory_newExplosion();

void Factory_newImage();

