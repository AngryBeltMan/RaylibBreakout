#include "ui.h"
#include "block.h"
#include "data.h"
#include <raylib.h>
#include <stdio.h>
bool draw_gameover(Block*P_block_array,float* P_dx,float *P_dy) {
    Vector2 gameover_pos = (Vector2){(SCREENWIDTH/2.) - 100,(SCREENHEIGHT/2.) - 50};
    Vector2 gameover_size = (Vector2){200,100};
    DrawRectangleV(gameover_pos,gameover_size,RED);
    DrawText("Retry",(SCREENWIDTH/2) - 85, (SCREENHEIGHT/2) -30, 60,WHITE);
    *P_dx = 0;
    *P_dy = 0;
    Vector2 mouse_pos = {GetMouseX(),GetMouseY()};
    if (
            (mouse_pos.x > gameover_pos.x)
            && (mouse_pos.x < gameover_pos.x + gameover_size.x)
            && (mouse_pos.y > gameover_pos.y)
            && (mouse_pos.y < gameover_pos.y + gameover_size.y)
            && IsMouseButtonDown(MOUSE_BUTTON_LEFT)
        ) {
        *P_dx = 120;
        *P_dy = 250;
        lives = 3;
        make_blocks(P_block_array);
        return true;
    } else {
        return false;
    }
}
void draw_victory(float *P_dx,float *P_dy) {
    Vector2 pos = (Vector2){(SCREENWIDTH/2.) - 200,(SCREENHEIGHT/2.) - 50};
    Vector2 size = (Vector2){400,100};
    *P_dx = 0;
    *P_dy = 0;
    DrawRectangleV(pos, size, GREEN);
    DrawText("YOU WIN!",(SCREENWIDTH/2) - 130, (SCREENHEIGHT/2) -30, 60,WHITE);
}
