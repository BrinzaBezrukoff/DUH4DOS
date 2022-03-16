
#include "DUH/BLOCK.h"

Block _blocks[256] = {
        {EMPTY, 0, false, WHITE, BLACK, false},
        {WALL, 219, true, WHITE, BLACK, false},
        {ENTRY_POINT, 0, false, WHITE, BLACK, false},
        {TARGET_POINT, 127, false, GREEN, BLACK, true},
        {MED_KIT, 3, false, RED, BLACK, false},
        {WATER_JUG, 21, false, CYAN, BLACK, false},
        {COIN, 111, false, YELLOW, BLACK, false},
};

bool isSolid(uchar id) {
    return _blocks[id].solid;
}

uchar getSymbol(uchar id) {
    return _blocks[id].symbol;
}

Block *getBlock(uchar id) {
    return &_blocks[id];
}

Block initBlock(uchar id, uchar symbol, bool solid) {
    Block block;
    block.ID = id;
    block.symbol = symbol;
    block.solid = solid;
    block.color = WHITE;
    return block;
}
