#ifndef DUH4DOS_BLOCK_H
#define DUH4DOS_BLOCK_H

#include <conio.h>

#include "DUH/TOOLS.H"

typedef struct Block {
    uint ID;
    uchar symbol;
    bool solid;
    COLORS color;
} Block;

extern Block _blocks[255];

Block initBlock(uint id, uchar symbol, bool solid);
bool isSolid(uint id);
uchar getSymbol(uint id);

#endif
