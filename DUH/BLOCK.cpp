
#include "DUH/BLOCK.h"

Block _blocks[255] = {
        {0, 0, false, WHITE},
        {1, 219, true, WHITE}
};

bool isSolid(uint id) {
    return _blocks[id].solid;
}

uchar getSymbol(uint id) {
    return _blocks[id].symbol;
}

Block initBlock(uint id, uchar symbol, bool solid) {
    Block block;
    block.ID = id;
    block.symbol = symbol;
    block.solid = solid;
    block.color = WHITE;
    return block;
}
