#ifndef __DUH_MAP_H
#define __DUH_MAP_H

#include <stdio.h>
#include "DUH/TOOLS.H"

#define DEF_WIDTH 80
#define DEF_HEIGHT 25

const uchar LINE_HOR = 196;
const uchar LINE_VER = 179;
const uchar CORN_TL = 219;
const uchar CORN_TR = 191;
const uchar CORN_BL = 192;
const uchar CORN_BR = 217;
const uchar EMPTY = 0;

typedef struct Map {
	uchar *_map;
    uint _width;
    uint _height;
} Map;

void redrawMap(Map *map);
bool isValid(Map *map, uint x, uint y);
bool isFree(Map *map, uint x, uint y);
uchar getSym(Map *map, uint x, uint y);
void setSym(Map *map, uint x, uint y, uchar sym);
void initMap(Map *map, uint width, uint height);
void freeMap(Map *map);
bool parseFile(Map *map, FILE *file);
void saveFile(Map *map, FILE *file);

#endif