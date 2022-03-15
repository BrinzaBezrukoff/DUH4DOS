#include <stdio.h>

#include "DUH/TOOLS.H"


int putonxy(int c, uint x, uint y) {
    gotoxy(x, y);
    return cprintf("%c", c);
}

void setcolors(COLORS fg, COLORS bg, bool blink) {
    int attr;
    attr = fg | bg << 4;
    if (blink) {
        attr |= BLINK;
    } else {
        attr &= ~BLINK;
    }
    textattr(attr);
}

void resetcolors() {
    struct text_info ti;
    gettextinfo(&ti);
    textattr(ti.normattr);
}
