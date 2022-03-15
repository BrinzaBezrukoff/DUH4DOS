
#include "DUH/BLOCK.h"

Block _blocks[255] = {
        {0, 0, false, WHITE},
        {1, 196, true, WHITE},
        {2, 179, true, WHITE},
        {3, 218, true, WHITE},
        {4, 191, true, WHITE},
        {5, 192, true, WHITE},
        {6, 217, true, WHITE},
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
