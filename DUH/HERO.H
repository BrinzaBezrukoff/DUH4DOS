#ifndef __DUH_HERO_H
#define __DUH_HERO_H

#include "DUH/TOOLS.H"
#include "DUH/MAP.H"

#define HEROSYM 1


typedef struct Hero {
	uint _x, _y;
	uint _oldx, _oldy;

	uint _water;
	uint _hp;
	uint _coins;

	Map *map;
} Hero;

void initHero(Hero *hero, uint x, uint y, Map* map);
void redrawHero(Hero *hero);
bool moveHero(Hero *hero, uint dx, uint dy);
bool tpHero(Hero *hero, uint x, uint y);
GameState handlePos(Hero *hero);


#endif