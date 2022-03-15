#include <stdlib.h>

#include "DUH/TOOLS.H"

#include "DUH/MAP.H"
#include "DUH/BLOCK.H"


void redrawPos(Map *map, uint x, uint y) {
    Block *block = getBlock(getId(map, x, y));
    cputonxy(block->symbol, x, y, block->color, BLACK, false);
}

void redrawMap(Map *map) {
	int x, y;
	for (y = 1; y <= map->_height; y++) {
		for (x = 1; x <= map->_width; x++) {
            redrawPos(map, x, y);
		}
	}
}

bool isValid(Map *map, uint x, uint y) {
	return (x >= 1 && x <= map->_width) && (y >= 1 && y <= map->_height);
}

bool isFree(Map *map, uint x, uint y) {
    return !isSolid(getId(map, x, y));
}

uchar getId(Map *map, uint x, uint y) {
	return map->_map[(y - 1) * map->_width + x - 1];
}

void setId(Map *map, uint x, uint y, uchar id) {
    map->_map[(y - 1) * map->_width + x - 1] = id;
}

void initMap(Map *map, uint width, uint height) {
    map->_width = width;
    map->_height = height;
    map->_map = (uchar*) calloc(map->_width * map->_height, sizeof(uchar));
    if (map->_map == NULL) {
        fprintf(stderr, "Can't allocate memory for map!\n");
        exit(1);
    }
}

void freeMap(Map *map) {
    free(map->_map);
}

bool parseFile(Map *map, FILE *file) {
	uint width, height;
    size_t len1, len2;
    uint arrLen;
    len1 = fread(&width, sizeof(uint), 1, file);
    len2 = fread(&height, sizeof(uint), 1, file);
	if (!len1 || !len2 || width != map->_width || height != map->_height) {
		return false;
	}
    arrLen = map->_width * map->_height;
    len1 = fread(map->_map, sizeof(uchar), arrLen, file);
    if (arrLen != len1) {
        return false;
    }
	return true;
}

void saveFile(Map *map, FILE *file) {
    fwrite(&map->_width, sizeof(uint), 1, file);
    fwrite(&map->_height, sizeof(uint), 1, file);
    fwrite(map->_map, sizeof(uchar), map->_width * map->_height, file);
}
