#ifndef __DUH_MAP_H
#define __DUH_MAP_H

#include <stdio.h>
#include "TOOLS.H"

#define WIDTH 4
#define HEIGHT 4


typedef struct Map {
	uchar _map[WIDTH][HEIGHT];

} Map;

void redrawMap(Map *map);
bool isValid(Map *map, uint x, uint y);
uchar getSym(Map *map, uint x, uint y);
bool initMap(Map *map, FILE *file);
void freeMap(Map *map);

#endif