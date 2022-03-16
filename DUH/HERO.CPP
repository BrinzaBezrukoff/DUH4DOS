#include "DUH/TOOLS.H"

#include "DUH/HERO.H"
#include "DUH/MAP.H"
#include "DUH/BLOCK.H"


void initHero(Hero *hero, uint x, uint y, Map* map) {
	hero->_x = hero->_oldx = x;
	hero->_y = hero->_oldy = y;
	hero->_water = 10u;
	hero->_hp = 10u;
	hero->_coins = 0u;
	hero->map = map;
}

void redrawHero(Hero *hero) {
    redrawPos(hero->map, hero->_oldx, hero->_oldy);
    setcolors(WHITE, BLACK, false);
	putonxy(HEROSYM, hero->_x, hero->_y);
    resetcolors();
}

bool moveHero(Hero *hero, uint dx, uint dy) {
	return tpHero(hero, hero->_x + dx, hero->_y + dy);
}

bool tpHero(Hero *hero, uint x, uint y) {
	if (!isValid(hero->map, x, y)) {
		return false;
	}
    if (!isFree(hero->map, x, y)) {
        return false;
    }
    hero->_oldx = hero->_x;
    hero->_oldy = hero->_y;
	hero->_x = x;
	hero->_y = y;
	return true;
}

GameState handlePos(Hero *hero) {
    uchar id = getId(hero->map, hero->_x, hero->_y);
    switch (id) {
        case MED_KIT:
            hero->_hp += 10;
            setId(hero->map, hero->_x, hero->_y, 0);
            break;
        case WATER_JUG:
            hero->_water += 10;
            setId(hero->map, hero->_x, hero->_y, 0);
            break;
        case COIN:
            hero->_coins += 10;
            setId(hero->map, hero->_x, hero->_y, 0);
            break;
        case TARGET_POINT:
            return END_WIN;
    }
    return CONTINUE;
}
