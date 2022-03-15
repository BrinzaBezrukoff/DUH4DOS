#include <conio.h>
#include <stdio.h>
#include <ctype.h>

#include "DUH/TOOLS.H"
#include "DUH/MAP.H"
#include "DUH/BLOCK.H"


int main() {
    char filename[64] = "";
    int isNew;
    bool running;
    Map map;
    FILE *file;
    uint pressed;
	uint x, y;
	struct text_info ti;

	gettextinfo(&ti);
	printf("%dx%d\n", ti.screenwidth, ti.screenheight);

	printf("File to edit: ");
    scanf("%s", filename);
	printf("New? [1/0]: ");
	scanf("%d", &isNew);

	initMap(&map, DEF_WIDTH - 1, DEF_HEIGHT - 1);
    if (isNew) {
        file = fopen(filename, "wb");
        saveFile(&map, file);
        fclose(file);
    }
    else {
        file = fopen(filename, "rb");
        parseFile(&map, file);
        fclose(file);
    }

    running = true;
    x = 1;
    y = 1;

    while (running) {
        redrawMap(&map);

        gotoxy(x, y);

        pressed = getch();
        switch (pressed) {
            case 'w': y--; break;
            case 'a': x--; break;
            case 's': y++; break;
            case 'd': x++; break;
            case 'q': running = false; break;
            default:
                if (isdigit(pressed)) {
                    setId(&map, x, y, pressed - '0');
                }
                break;
        }
    }

    clrscr();

    file = fopen(filename, "wb");
    saveFile(&map, file);
    fclose(file);

    freeMap(&map);

    printf("Done!\n");

    return 0;
}
