#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "TOOLS.H"
#include "HERO.H"
#include "MAP.H"


int main() {
	Map map;
	Hero hero;
	struct text_info ti;
	bool running;
	FILE* file;
	uint pressed;

	file = fopen("LVLS/LEVEL1.DAT", "rb");
	if (file == NULL) {
		fprintf(stderr, "Level file not foun!\n");
		exit(1);
	}
	initMap(&map, WIDTH, HEIGHT);
    parseFile(&map, file);
	fclose(file);

	initHero(&hero, 2u, 2u,&map);

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

	return 0;
}
