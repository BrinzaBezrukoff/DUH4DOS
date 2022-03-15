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

// Pseudo-graphics
const uchar LINE_HOR = 196;
const uchar LINE_VER = 179;
const uchar CORN_TL = 219;
const uchar CORN_TR = 191;
const uchar CORN_BL = 192;
const uchar CORN_BR = 217;
const uchar EMPTY = 0;

// putchar on (x, y) with textattrs
int putonxy(int c, uint x, uint y);
// putchar on (x, y) with passed textattrs
int cputonxy(int c, uint x, uint y, COLORS fg, COLORS bg, bool blink);

#endif