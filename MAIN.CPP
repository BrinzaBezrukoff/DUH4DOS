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

	file = fopen("level1.dat", "rb");
	if (file == NULL) {
		fprintf(stderr, "Level file not foun!\n");
		exit(1);
	}
	initMap(&map, file);
	fclose(file);

	initHero(&hero, 1u, 1u, &map);

	gettextinfo(&ti);
	clrscr();
	_setcursortype(_NOCURSOR);

	while (running) {
		redrawMap(&map);
		redrawHero(&hero);
		getch();
		clrscr();
	}

	clrscr();
	printf("Bye ");
	putch(1);
	putch('\n');

	getch();

	freeMap(&map);

	return 0;
}
