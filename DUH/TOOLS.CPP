#include <conio.h>
#include <stdio.h>

#include "DUH/TOOLS.H"


int putonxy(int c, uint x, uint y) {
    gotoxy(x, y);
    return putchar(c);
}

