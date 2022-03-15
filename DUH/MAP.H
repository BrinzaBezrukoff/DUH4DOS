#ifndef __DUH_MAP_H
#define __DUH_MAP_H

#include <stdio.h>
#include "DUH/TOOLS.H"

#define DEF_WIDTH 80
#define DEF_HEIGHT 25

typedef struct Map {
	uchar *_map;
    uint _width;
    uint _height;
} Map;

void redrawPos(Map *map, uint x, uint y);
void redrawMap(Map *map);
bool isValid(Map *map, uint x, uint y);
bool isFree(Map *map, uint x, uint y);
uchar getId(Map *map, uint x, uint y);
void setId(Map *map, uint x, uint y, uchar sym);
void initMap(Map *map, uint width, uint height);
void freeMap(Map *map);
bool parseFile(Map *map, FILE *file);
void saveFile(Map *map, FILE *file);

#endif