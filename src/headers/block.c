#include "block.h"
#include "raylib.h"
void make_blocks(Block*P_block_array) {
  int index = 0;
  for (int row = 0; row < 6; ++row) {
    for (int column = 0; column < 8; ++column) {
      P_block_array[index] = (Block){false,(Vector2){(column * 100) + 30, (row * 35) + 30}};
      ++index;
    }
  }
}
