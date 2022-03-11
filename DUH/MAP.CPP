#include <conio.h>
#include <stdlib.h>

#include "DUH/MAP.H"
#include "DUH/BLOCK.H"


void redrawMap(Map *map) {
	int x, y;
	for (y = 1; y <= map->_height; y++) {
		for (x = 1; x <= map->_width; x++) {
			gotoxy(x, y);
			putchar(getSymbol(getId(map, x, y)));
		}
	}
}

bool isValid(Map *map, uint x, uint y) {
	return (x >= 1 && x <= map->_width) && (y >= 1 && y <= map->_height);
}

bool isFree(Map *map, uint x, uint y) {
    return (bool) getId(map, x, y) == 0;
}

uchar getId(Map *map, uint x, uint y) {
	return map->_map[(y - 1) * map->_width + x - 1];
}

void setId(Map *map, uint x, uint y, uchar sym) {
    map->_map[(y - 1) * map->_width + x - 1] = sym;
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
	fread(&width, sizeof(uint), 1, file);
	fread(&height, sizeof(uint), 1, file);
	if (width != map->_width || height != map->_height) {
		return false;
	}
	fread(map->_map, sizeof(uchar), map->_width * map->_height, file);
	return true;
}

void saveFile(Map *map, FILE *file) {
    fwrite(&map->_width, sizeof(uint), 1, file);
    fwrite(&map->_height, sizeof(uint), 1, file);
    fwrite(map->_map, sizeof(uchar), map->_width * map->_height, file);
}
