#include <stdio.h>
#include "raylib.h"
#include "data.h"
#include "block.h"
#define COLLIDING(pos1,pos2,w1,h1,w2,h2) ((pos1->x + w1 > pos2->x) && (pos1->x - w1 < pos2->x + w2) && (pos1->y + h1 > pos2->y) && (pos1->y - h1 < pos2->y + h2))

void colliding_wall(Vector2 *ball_pos, float *ball_dx, float *ball_dy);
void colliding_paddle(Vector2 *ball_pos,Vector2 * paddle_pos, float *x_velocity,float *y_velocity);
void colliding_blocks(Vector2 *ball_pos, Block *blocks, float*x_velocity, float*y_velocity,Sound *pop);

void movement_test(Vector2 *ball_pos,Vector2 *player_pos,Block *blocks, float *ball_dx, float *ball_dy) {
    ball_pos->y += *ball_dy;
    ball_pos->x += *ball_dx;
}
void move_ball(Vector2 *ball_pos,Vector2 *player_pos,Block *blocks, float *ball_dx, float *ball_dy,Sound*popsfx) {
    colliding_wall(ball_pos,ball_dx,ball_dy);
    colliding_paddle(ball_pos,player_pos,ball_dx,ball_dy);
    colliding_blocks(ball_pos,blocks,ball_dx,ball_dy,popsfx);
    ball_pos->y += *ball_dy * GetFrameTime();
    ball_pos->x += *ball_dx * GetFrameTime();
}

void colliding_wall(Vector2 *ball_pos, float *ball_dx, float *ball_dy) {
    if (ball_pos->x > SCREENWIDTH) { *ball_dx *= -1; }
    if (ball_pos->x < 0) {
        printf("game over");
        *ball_dx *= -1;
    }
    if (ball_pos->y > SCREENHEIGHT) { *ball_dy *= -1; }
    if (ball_pos->y < 0) { *ball_dy *= -1; }
}
void colliding_paddle(Vector2 *ball_pos,Vector2 * paddle_pos, float *x_velocity,float *y_velocity) {
    Vector2 *pos_x_next = &(Vector2){ball_pos->x + (*x_velocity * GetFrameTime()) ,ball_pos->y};
    Vector2 *pos_y_next = &(Vector2){ball_pos->x ,ball_pos->y + (*y_velocity * GetFrameTime())};
    if (COLLIDING(pos_x_next,paddle_pos,BALLRADIUS,BALLRADIUS,PLAYERWIDTH,PLAYERHEIGHT)) {
        *x_velocity *= -1;
    }
    if (COLLIDING(pos_y_next,paddle_pos,BALLRADIUS,BALLRADIUS,PLAYERWIDTH,PLAYERHEIGHT)) {
        *y_velocity *= -1;
    }
}
void colliding_blocks(Vector2 *ball_pos, Block *blocks, float*x_velocity, float*y_velocity,Sound *pop) {
    Vector2 *pos_x_next = &(Vector2){ball_pos->x + (*x_velocity * GetFrameTime()) , ball_pos->y};
    Vector2 *pos_y_next = &(Vector2){ball_pos->x ,ball_pos->y + (*y_velocity * GetFrameTime()) };
    for (int i = 0;i < BLOCKS;++i) {
        Block *block = &blocks[i];
        if (block != NULL) {
            PlaySound(*pop);
            if (COLLIDING(pos_x_next, (&block->pos), BALLRADIUS,BALLRADIUS,BLOCKWIDTH, BLOCKHEIGHT) && (!block->deleted)) {
                *x_velocity *= -1.075;
                block->deleted = true;
            }
            if (COLLIDING(pos_y_next, (&block->pos), BALLRADIUS,BALLRADIUS,BLOCKWIDTH, BLOCKHEIGHT) && (!block->deleted)) {
                *y_velocity *= -1.075;
                block->deleted = true;
            }
        }
    }
}
