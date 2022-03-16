#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <dos.h>

#include "DUH/TOOLS.H"
#include "DUH/HERO.H"
#include "DUH/MAP.H"
#include "DUH/HUD.H"

#define DEF_LVL "LVLS/1.DAT"
#define FPS 30

const uint frameDelay = (float) 1000 / FPS;


int main() {
	Map map;
	Hero hero;
	struct text_info ti;
	FILE* file;
	uint pressed;
    char filename[64] = "";
    size_t len;
    GameState gameState = CONTINUE;

    printf("Level file [empty for default]: ");
    fgets(filename, 64, stdin);
    if ((len = strlen(filename)) < 2) {
        strcpy(filename, DEF_LVL);
    }
    else {
        filename[len - 1] = '\0';
    }
	file = fopen(filename, "rb");
	if (file == NULL) {
		fprintf(stderr, "Level file not found!\n");
        getch();
		exit(1);
	}
	initMap(&map, DEF_WIDTH - 1, DEF_HEIGHT - 1);
    if (!parseFile(&map, file)) {
        fprintf(stderr, "Level file not loaded!\n");
        getch();
        exit(1);
    }
	fclose(file);

	initHero(&hero, 2u, 2u, &map);

	gettextinfo(&ti);
	clrscr();
	_setcursortype(_NOCURSOR);

    redrawMap(&map);
    redrawHero(&hero);
    redrawHUD(&hero, &map);

	while (gameState == CONTINUE) {
        if (kbhit()) {
            pressed = getch();
            switch (pressed) {
                case 'w':
                    moveHero(&hero, 0, -1);
                    break;
                case 'a':
                    moveHero(&hero, -1, 0);
                    break;
                case 's':
                    moveHero(&hero, 0, 1);
                    break;
                case 'd':
                    moveHero(&hero, 1, 0);
                    break;
                case 'q':
                    gameState |= END_QUIT;
                    break;
                default:
                    break;
            }
            gameState |= handlePos(&hero);
            redrawHero(&hero);
            redrawHUD(&hero, &map);
        }
        delay(frameDelay);
	}

    freeMap(&map);
    clrscr();
    _setcursortype(_NORMALCURSOR);

    if (gameState & END_WIN) {
        setcolors(GREEN, BLACK, true);
        gotoxy(DEF_WIDTH / 2 - 8, 1);
        cprintf("You won!\n");
        setcolors(YELLOW, BLACK, false);
        gotoxy(DEF_WIDTH / 2 - 8, 2);
        cprintf("Coins: %d\n", hero._coins);
    } else if (gameState & END_QUIT) {
        setcolors(WHITE, BLACK, false);
        gotoxy(DEF_WIDTH / 2 - 8, 1);
        cprintf("Goodbye %c!\n", 1);
    }

    resetcolors();

	return 0;
}
