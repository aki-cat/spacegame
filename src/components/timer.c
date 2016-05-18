
#include "config/time.h"
#include "utility/macros.h"
#include "components/timer.h"

#include <stdbool.h>
#include <stdio.h>

struct _timer {
    int counter;
    int total;
    bool active;
};

static Timer TIMERS[TIMER_POOL_SIZE];

void Timer_init() {
    int id;

    for (id = 0; id < TIMER_POOL_SIZE; ++id) {
        TIMERS[id].active = false;
        TIMERS[id].counter = 0;
        TIMERS[id].total = 0;
    }
}

int Timer_new(double secs) {
    int id;

    for (id = 0; id < TIMER_POOL_SIZE; ++id) {
        if (!TIMERS[id].active) {
            TIMERS[id].counter = TIMERS[id].total = (int)(Time_getFramerate() * secs);
            TIMERS[id].active = true;
            printf("NEW TIMER: %d\n", TIMERS[id].counter);
            return id;
        }
    }
    pool_overflow(Timer);
}

void Timer_update() {
    int id;

    for (id = 0; id < TIMER_POOL_SIZE; ++id)
        if (TIMERS[id].active && TIMERS[id].counter >= 0){
            printf("%d\n", --TIMERS[id].counter);
        }
}

float Timer_progress(int id) {
    return (TIMERS[id].active ? 100.0*( (TIMERS[id].total - TIMERS[id].counter) / TIMERS[id].total ) : -1);
}

bool Timer_isDone(int id) {
    bool done = false;
    printf("TIMER #%d PROGRESS: %f\n", id, Timer_progress(id));
    if (id == -1) done = true;
    else if (TIMERS[id].active) {
        if (TIMERS[id].counter <= 0) {
            TIMERS[id].active = false;
            done = true;
        }
    }
            
    return done;
}




