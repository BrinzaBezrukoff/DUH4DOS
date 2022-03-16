#ifndef __DUH_BLOCK_H
#define __DUH_BLOCK_H

#include "DUH/TOOLS.H"


typedef enum BlockType {
    EMPTY,
    WALL,
    ENTRY_POINT,
    TARGET_POINT,
    MED_KIT,
    WATER_JUG,
    COIN
} BlockType;

typedef struct Block {
    uchar ID;
    uchar symbol;
    bool solid;
    COLORS color;
    COLORS background;
    bool blink;
} Block;

extern Block _blocks[256];

Block initBlock(uchar id, uchar symbol, bool solid);
bool isSolid(uchar id);
uchar getSymbol(uchar id);
Block *getBlock(uchar id);

#endif
