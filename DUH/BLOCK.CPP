
#include "DUH/BLOCK.h"

Block _blocks[256] = {
        {0, 0, false, WHITE},
        {1, 219, true, WHITE},
        {2, 0, false, WHITE},
        {3, 127, false, GREEN},
        {4, 3, false, RED},
        {5, 21, false, CYAN},
        {6, 7, false, YELLOW},
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
