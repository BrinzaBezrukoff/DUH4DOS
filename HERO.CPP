#include <conio.h>

#include "HERO.H"


void initHero(Hero *hero, uint x, uint y, Map* map) {
	hero->_x = hero->_oldx = x;
	hero->_y = hero->_oldy = y;
	hero->_water = 100u;
	hero->_hp = 100u;
	hero->_coins = 0u;
	hero->map = map;
}

void redrawHero(Hero *hero) {
	gotoxy(hero->_oldx, hero->_oldy);
	putchar(0);
	gotoxy(hero->_x, hero->_y);
	putchar(HEROSYM);
}

bool moveHero(Hero *hero, uint dx, uint dy) {
	return tpHero(hero, hero->_x + dx, hero->_y + dy);
}

bool tpHero(Hero *hero, uint x, uint y) {
	if (isValid(hero->map, x, y)) {
		return false;
	}
	hero->_x = x;
	hero->_y = y;
	return true;
}