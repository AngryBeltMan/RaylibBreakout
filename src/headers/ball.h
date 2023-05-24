#include "raylib.h"
#include "block.h"
#include "data.h"

#ifndef INITBALL

#define INITBALL(w,h) \
    Vector2 ball_pos = {w/2.,h-80.}; \
    float ball_dx  =  0; \
    float ball_dy  =  0;
#endif

void move_ball(
        Vector2 *ball_pos,
        Vector2 *player_pos,
        Block *blocks,
        float *ball_dx,
        float *ball_dy,
        Sound *popsfx,
        Sound *hurt
);
