#include <conio.h>

#include "DUH/HUD.H"


void redrawHUD(Hero *hero, Map *map) {
    gotoxy(1, DEF_HEIGHT);
    clreol();
    setcolors(RED, BLACK, false);
    cprintf("HP: %u", hero->_hp);
    gotoxy(DEF_WIDTH * 1 / 3 + 1, DEF_HEIGHT);
    setcolors(CYAN, BLACK, false);
    cprintf("WATER: %u", hero->_water);
    gotoxy(DEF_WIDTH * 2 / 3 + 1, DEF_HEIGHT);
    setcolors(YELLOW, BLACK, false);
    cprintf("COINS: %u", hero->_coins);
    resetcolors();
}
