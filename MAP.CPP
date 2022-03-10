#include <conio.h>
#include <stdlib.h>

#include "MAP.H"


void redrawMap(Map *map) {
	int x, y;
	for (y = 1; y <= map->_height; y++) {
		for (x = 1; x <= map->_width; x++) {
			gotoxy(x, y);
			putchar(getSym(map, x, y));
		}
	}
}

bool isValid(Map *map, uint x, uint y) {
	return (x >= 1 && x <= map->_width) && (y >= 1 && y <= map->_height);
}

uchar getSym(Map *map, uint x, uint y) {
	return map->_map[y - 1][x - 1];
}

void setSym(Map *map, uint x, uint y, uchar sym) {
    map->_map[y - 1][x - 1] = sym;
}

void initMap(Map *map, uint width, uint height) {
    int i, j;
    map->_width = width;
    map->_height = height;
    for (i = 0; i < map->_height; i++) {
        for (j = 0; j < map->_width; j++) {
            map->_map[i][j] = 0;
        }
    }
}

void freeMap(Map *map) {

}

bool parseFile(Map *map, FILE *file) {
	uint width, height;
	fread(&width, sizeof(uint), 1, file);
	fread(&height, sizeof(uint), 1, file);
	if (width != map->_width || map->_height != HEIGHT) {
		return false;
	}
	fread(map->_map, sizeof(uchar), WIDTH * HEIGHT, file);
	return true;
}

void saveFile(Map *map, FILE *file) {
    fwrite(&map->_width, sizeof(uint), 1, file);
    fwrite(&map->_height, sizeof(uint), 1, file);
    fwrite(map->_map, sizeof(uchar), map->_width * map->_height, file);
}
