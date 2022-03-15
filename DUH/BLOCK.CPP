
#include "DUH/BLOCK.h"

Block _blocks[256] = {
        {0, 0, false, WHITE},
        {1, 219, true, WHITE},
        {2, 0, false, WHITE},
        {3, 177, false, GREEN}
};

bool isSolid(uchar id) {
    return _blocks[id].solid;
}

uchar getSymbol(uchar id) {
    return _blocks[id].symbol;
}

Block initBlock(uchar id, uchar symbol, bool solid) {
    Block block;
    block.ID = id;
    block.symbol = symbol;
    block.solid = solid;
    block.color = WHITE;
    return block;
}
