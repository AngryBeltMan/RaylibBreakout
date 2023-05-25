#include "raylib.h"
#define SCREENWIDTH 800
#define SCREENHEIGHT 450
#define PLAYERWIDTH 120
#define PLAYERHEIGHT 50
#define BLOCKWIDTH 50
#define BALLRADIUS 10
#define BLOCKHEIGHT 25
#define BLOCKS 48
#define FPS 60
#ifndef LIVES
#define LIVES
static int lives = 3;
static Vector2 player_pos = {SCREENWIDTH / 2.5, SCREENHEIGHT - 35};
#endif
