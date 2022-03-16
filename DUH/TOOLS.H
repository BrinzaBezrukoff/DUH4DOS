#ifndef __DUH_TOOLS_H
#define __DUH_TOOLS_H

#include <conio.h>

// Uint type
typedef unsigned int uint;

// Boolean type
typedef uint bool;
const uint true = 1u;
const uint false = 0u;

// Symbol type (uchar)
typedef unsigned char uchar;

// putchar on (x, y) with textattrs
int putonxy(int c, uint x, uint y);
// set color attrs
void setcolors(COLORS fg, COLORS bg, bool blink);
// reset color attrs to normal attrs for system
void resetcolors();

// Game states
typedef enum GameState {
    CONTINUE = 0,
    END_WIN = 1,
    END_QUIT = 2
} GameState;

#endif