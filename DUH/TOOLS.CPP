#include <stdio.h>

#include "DUH/TOOLS.H"

#define DOS_ATTR (LIGHTGRAY | BLACK << 4 & ~BLINK)


int putonxy(int c, uint x, uint y) {
    gotoxy(x, y);
    return cprintf("%c", c);
}

int cputonxy(int c, uint x, uint y, COLORS fg, COLORS bg, bool blink) {
    int ret, attr;
    attr = fg | bg << 4;
    if (blink) {
        attr |= BLINK;
    } else {
        attr &= ~BLINK;
    }
    textattr(attr);
    ret = putonxy(c, x, y);
    textattr(DOS_ATTR);
    return ret;
}

