#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "DUH/TOOLS.H"
#include "DUH/HERO.H"
#include "DUH/MAP.H"


#define DEF_LVL "LVLS/1.DAT"


int main() {
	Map map;
	Hero hero;
	struct text_info ti;
	bool running;
	FILE* file;
	uint pressed;
    char filename[64] = "";
    size_t len;

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

	while (running) {
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
                    running = false;
                    break;
                default:
                    break;
            }
        }
        redrawHero(&hero);
	}

	clrscr();
	printf("Bye ");
	putch(1);
	putch('\n');

	getch();

	freeMap(&map);

    _setcursortype(_NORMALCURSOR);

	return 0;
}
