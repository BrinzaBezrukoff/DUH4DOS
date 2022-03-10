#ifndef __DUH_MAP_H
#define __DUH_MAP_H

#include <stdio.h>
#include "TOOLS.H"

#define WIDTH 80
#define HEIGHT 25


typedef struct Map {
	uchar _map[WIDTH][HEIGHT];
    uint _width;
    uint _height;
} Map;

void redrawMap(Map *map);
bool isValid(Map *map, uint x, uint y);
uchar getSym(Map *map, uint x, uint y);
void initMap(Map *map, uint width, uint height);
void freeMap(Map *map);
bool parseFile(Map *map, FILE *file);
void saveFile(Map *map, FILE *file);

#endif