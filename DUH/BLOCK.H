#ifndef __DUH_BLOCK_H
#define __DUH_BLOCK_H

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
