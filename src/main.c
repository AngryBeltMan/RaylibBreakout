#include "headers/ball.h"
#include "headers/ball_movement.c"
#include "headers/data.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

INITBALL(SCREENWIDTH, SCREENHEIGHT);

int main(void) {
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib [core] example - basic window");

  InitAudioDevice();
  Sound pop_noise; ; // the noise played when a block is destroyed
  Music music; ; // the noise played when a block is destroyed
  while (!IsAudioDeviceReady()) { }
  pop_noise = LoadSound("../assets/audio/pop.ogg");
  music = LoadMusicStream("../assets/audio/bg_music.mp3");

  SetTargetFPS(FPS);

  Vector2 player_pos = {SCREENWIDTH / 2.5, SCREENHEIGHT - 35};

  Block *block_array = NULL;

  block_array = (Block *)malloc(sizeof(Block) * BLOCKS);

  int index = 0;
  for (int row = 0; row < 6; ++row) {
    for (int column = 0; column < 8; ++column) {
      block_array[index] = (Block){false,(Vector2){(column * 100) + 30, (row * 35) + 30}};
      ++index;
    }
  }
  printf("length %i \n", index);
  PlayMusicStream(music);
  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_LEFT) && player_pos.x > 0) {
      player_pos.x -= GetFrameTime() * 500.;
      PlaySound(pop_noise);
    }
    if (IsKeyDown(KEY_RIGHT) && player_pos.x + PLAYERWIDTH < SCREENWIDTH) {
      player_pos.x += GetFrameTime() * 500.;
    }

    move_ball(&ball_pos, &player_pos, block_array, &ball_dx, &ball_dy,&pop_noise);

    BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i = 0; i < BLOCKS; ++i) {
          Block *block = &block_array[i];
          if ((block == NULL) | block->deleted) { continue; }

          DrawRectangleV(block->pos, (Vector2){BLOCKWIDTH, BLOCKHEIGHT}, BLACK);
        }
        DrawRectangleV(player_pos, (Vector2){PLAYERWIDTH, PLAYERHEIGHT}, RED);
        DrawCircleV(player_pos, 1.0, BLACK);
        DrawCircleV(ball_pos, BALLRADIUS, BLUE);
    EndDrawing();
  }              // Detect window close button or ESC key
  UnloadSound(pop_noise);
  UnloadMusicStream(music);
  CloseAudioDevice();
  CloseWindow(); // Close window and OpenGL context
  free(block_array);
  return 0;
}
