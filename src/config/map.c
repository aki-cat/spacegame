
#include "map.h"

struct _map {
    float width;
    float height;
    float unit_x;
    float unit_y;
};

static Map MAPCONF;

void Map_init() {
    char *map_str = Conf_get(CONF_MAP);
    sscanf(map_str, "%f %f", &MAPCONF.width, &MAPCONF.height);
}

float Map_getWidth() {
    return MAPCONF.width;
}

float Map_getHeight() {
    return MAPCONF.height;
}

float Map_getUnitX() {
    return MAPCONF.unit_x;
}

float Map_getUnitY() {
    return MAPCONF.unit_y;
}