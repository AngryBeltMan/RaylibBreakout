#include "headers/ball.h"
#include "headers/ball_movement.c"
#include "headers/data.h"
#include "headers/ui.c"
#include "headers/block.c"
#include "raylib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

INITBALL(SCREENWIDTH, SCREENHEIGHT);

int main(void) {
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Pong!");

  InitAudioDevice();
  Sound music;// the noise played when a block is destroyed
  while (!IsAudioDeviceReady()) { } // spins until the Audio Device is ready

  music = LoadSound("../assets/audio/bg_music.mp3");
  Sound crush = LoadSound("../assets/audio/breaking.mp3");
  Sound hurt = LoadSound("../assets/audio/hurt.mp3");

  SetTargetFPS(FPS);

  Vector2 player_pos = {SCREENWIDTH / 2.5, SCREENHEIGHT - 35};

  Block *block_array = NULL;

  block_array = (Block *)malloc(sizeof(Block) * BLOCKS);
  make_blocks(block_array);

  PlaySound(music);
  ball_dx = 120;
  ball_dy = 250;
  while (!WindowShouldClose()) {
      /* printf("(%f,%f)\n",ball_pos.x,ball_pos.y); */
      if (IsKeyDown(KEY_LEFT) && player_pos.x > 0) {
          player_pos.x -= GetFrameTime() * ((abs((int)ball_dy)/1.5) + 400);
      }
      if (IsKeyDown(KEY_RIGHT) && player_pos.x + PLAYERWIDTH < SCREENWIDTH) {
          player_pos.x += GetFrameTime() * ((abs((int)ball_dy)/1.5) + 400);
      }

      if (GetFrameTime() < 0.1) { //makes sure the ball doesn't too much
          move_ball(&ball_pos, &player_pos, block_array, &ball_dx, &ball_dy,&crush,&hurt);
      }
      BeginDrawing();
          ClearBackground(RAYWHITE);
          for (int i = 0; i < BLOCKS; ++i) {
              Block *block = &block_array[i];
              if ((block == NULL) | block->deleted) { continue; }
              DrawRectangleV(block->pos, (Vector2){BLOCKWIDTH, BLOCKHEIGHT}, BLACK);
          }
          DrawRectangleV(player_pos, (Vector2){PLAYERWIDTH, PLAYERHEIGHT}, RED);
          DrawCircleV(ball_pos, BALLRADIUS, BLUE);
          if (lives < 1) {
              draw_gameover(block_array,&ball_dx,&ball_dy);
          }
      EndDrawing();
  }              // Detect window close button or ESC key
  UnloadSound(music);
  UnloadSound(hurt);
  UnloadSound(crush);
  CloseAudioDevice();
  CloseWindow(); // Close window and OpenGL context
  free(block_array);
  return 0;
}
