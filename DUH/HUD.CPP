#include <conio.h>

#include "DUH/HUD.H"


void redrawHUD(Hero *hero, Map *map) {
    gotoxy(1, DEF_HEIGHT);
    clreol();

    textattr(RED | BLACK << 4 & ~BLINK);
    cprintf("HP: %u", hero->_hp);

    gotoxy(DEF_WIDTH * 1 / 3 + 1, DEF_HEIGHT);
    textattr(CYAN | BLACK << 4 & ~BLINK);
    cprintf("WATER: %u", hero->_water);

    gotoxy(DEF_WIDTH * 2 / 3 + 1, DEF_HEIGHT);
    textattr(YELLOW | BLACK << 4 & ~BLINK);
    cprintf("COINS: %u", hero->_coins);

    textattr(LIGHTGRAY | BLACK << 4 & ~BLINK);
}
