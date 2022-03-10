#include <conio.h>
#include <stdlib.h>

#include "MAP.H"


void redrawMap(Map *map) {
	int x, y;
	for (y = 1; y <= HEIGHT; y++) {
		for (x = 1; x <= WIDTH; x++) {
			gotoxy(x, y);
			putchar(getSym(map, x, y));
		}
	}
}

bool isValid(Map *map, uint x, uint y) {
	return (x >= 1 && x <= WIDTH) && (y >= 1 && y <= HEIGHT);
}

uchar getSym(Map *map, uint x, uint y) {
	return map->_map[y - 1][x - 1];
}

bool initMap(Map *map, FILE *file) {
	size_t width, height;

	fread(&width, sizeof(uint), 1, file);
	fread(&height, sizeof(uint), 1, file);

	if (width != WIDTH || height != HEIGHT) {
		return false;
	}

	fread(map->_map, sizeof(uchar), WIDTH * HEIGHT, file);

	return true;
}

void freeMap(Map *map) {
	
}