#include "MAP.H"

#include <conio.h>
#include <stdlib.h>


void redrawMap(Map *map) {
	int x, y;
	uchar ch;
	for (y = map->_height; y >= 1; y--) {
		for (x = 1; x <= map->_width; x++) {
			gotoxy(x, 1);
			putchar(getSym(map, x, y));
		}
		gotoxy(1, 1);
		insline();
	}
}

bool isValid(Map *map, uint x, uint y) {
	return (x >= 1 && x <= map->_width) && (y >= 1 && y <= map->_height);
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