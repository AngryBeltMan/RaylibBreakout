#include "headers/ball.h"
#include "headers/ball_movement.c"
#include "headers/data.h"
#include "headers/ui.c"
#include "headers/block.c"
#include "headers/gamestate.h"
#include "raylib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

INITBALL(SCREENWIDTH, SCREENHEIGHT);

int main(void) {
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Breakout!");

  InitAudioDevice();
  Sound music;// the noise played when a block is destroyed
  while (!IsAudioDeviceReady()) { } // spins until the Audio Device is ready

  music = LoadSound("../assets/audio/bg_music.mp3");
  SetSoundVolume(music, 0.5);
  Sound crush = LoadSound("../assets/audio/breaking.mp3");
  SetSoundVolume(crush, 0.25);
  Sound hurt = LoadSound("../assets/audio/hurt.mp3");
  SetSoundVolume(hurt, 1.5);
  Sound bounce = LoadSound("../assets/audio/bounce.mp3");
  Texture trophy = LoadTexture("../assets/trophy.png");

  SetTargetFPS(FPS);

  Vector2 player_pos = {SCREENWIDTH / 2.5, SCREENHEIGHT - 35};

  Block *block_array = NULL;

  block_array = (Block *)malloc(sizeof(Block) * BLOCKS);
  make_blocks(block_array);

  PlaySound(music);
  ball_dx = 120;
  ball_dy = 250;
  // in playing mode
  GameState gamestate = 2;

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_LEFT) && player_pos.x > 0) {
          player_pos.x -= GetFrameTime() * ((abs((int)ball_dy)/1.5) + 400);
      }
      if (IsKeyDown(KEY_RIGHT) && player_pos.x + PLAYERWIDTH < SCREENWIDTH) {
          player_pos.x += GetFrameTime() * ((abs((int)ball_dy)/1.5) + 400);
      }

      if (GetFrameTime() < 0.1) { //makes sure the ball doesn't too much
          move_ball(&ball_pos,
                  &player_pos,
                  block_array,
                  &ball_dx,
                  &ball_dy,
                  &crush,
                  &hurt,
                  &bounce
                  );
      }
      BeginDrawing();
          ClearBackground(RAYWHITE);
          printf("%i\n",gamestate);
          switch (gamestate) {
              case 0: // winning case
                  draw_victory(&ball_dx,&ball_dy);
                  DrawTextureEx(trophy, (Vector2){0,SCREENHEIGHT/2.125},0,0.55, WHITE);
                  DrawTextureEx(trophy, (Vector2){SCREENWIDTH/1.5,SCREENHEIGHT/2.125},0,0.55, WHITE);
                  EndDrawing();
                  continue;
              case 1: // loss case
                  printf("drawing gameover\n");
                  if (draw_gameover(block_array,&ball_dx,&ball_dy)) { gamestate = 2; }
                  EndDrawing();
                  continue;
              case 2: // still playing  case
                  printf("drawing playing\n");
                  for (int i = 0; i < BLOCKS; ++i) {
                      Block *block = &block_array[i];
                      if ((block == NULL) | block->deleted) { continue; }
                      DrawRectangleV(block->pos, (Vector2){BLOCKWIDTH, BLOCKHEIGHT}, BLACK);
                  }
                  DrawRectangleV(player_pos, (Vector2){PLAYERWIDTH, PLAYERHEIGHT}, RED);
                  DrawCircleV(ball_pos, BALLRADIUS, BLUE);
                  if (lives < 1) {
                      gamestate = 1;
                  }
                  EndDrawing();
                  continue;
          }
  printf("new frame\n");
  }              // Detect window close button or ESC key
  UnloadSound(music);
  UnloadSound(hurt);
  UnloadSound(crush);
  UnloadSound(bounce);
  UnloadTexture(trophy);
  CloseAudioDevice();
  CloseWindow(); // Close window and OpenGL context
  free(block_array);
  return 0;
}
