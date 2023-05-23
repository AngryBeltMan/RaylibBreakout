#include "raylib.h"
/* typedef union BlockState { */
/*     bool deleted; */
/*     Vector2 pos; */
/* } BlockState; */

#ifndef BLOCKDATA
#define BLOCKDATA
typedef struct BlockData {
    bool deleted;
    Vector2 pos;
} Block;

#endif
