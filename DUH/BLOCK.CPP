
#include "DUH/BLOCK.h"

Block _blocks[256] = {
        {0, 0, false, WHITE, BLACK, false},
        {1, 219, true, WHITE, BLACK, false},
        {2, 0, false, WHITE, BLACK, false},
        {3, 127, false, GREEN, BLACK, true},
        {4, 3, false, RED, BLACK, false},
        {5, 21, false, CYAN, BLACK, false},
        {6, 7, false, YELLOW, BLACK, false},
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
