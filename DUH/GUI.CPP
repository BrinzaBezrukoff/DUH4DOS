#include <conio.h>
#include <string.h>

#include "DUH/GUI.H"


DButton getDButton(char text[GUI_BUTTON_SIZE],
                int ret_code) {
    struct DButton button;
    strcpy(button.text, text);
    button.ret_code = ret_code;
    button.active = false;
    return button;
}

void redrawDButton(DButton *button, uint x, uint y) {
    int i;
    setcolors(BLACK, LIGHTGRAY, button->active);
    for (i = 0; i < GUI_BUTTON_SIZE; i++) {
        putonxy(0, x + i, y);
    }
    gotoxy(x, y);
    cprintf("%s", button->text);
    resetcolors();
}

void initDMessageBox(DMessageBox *mb,
                     uint x,
                     uint y,
                     char text[GUI_TEXT_SIZE],
                     DButton bt_cancel,
                     DButton bt_yes,
                     DButton bt_no) {
    mb->x = x;
    mb->y = y;
    strcpy(mb->text, text);
    mb->bt_cancel = bt_cancel;
    mb->bt_yes = bt_yes;
    mb->bt_no = bt_no;
}

void redrawDMessageBox(DMessageBox *mb) {
    int x, y;

    setcolors(BLUE, CYAN, false);
    for (y = mb->y; y < mb->y + GUI_MB_HEIGHT; y++) {
        for (x = mb->x; x < mb->x + GUI_MB_WIDTH; x++) {
            putonxy(0, x, y);
        }
    }
    for (y = mb->y + 1; y < mb->y + GUI_MB_HEIGHT - 1; y++) {
        putonxy(186, mb->x, y);
        putonxy(186, mb->x + GUI_MB_WIDTH - 1, y);
    }
    for (x = mb->x + 1; x < mb->x + GUI_MB_WIDTH - 1; x++) {
        putonxy(205, x, mb->y);
        putonxy(205, x, mb->y + GUI_MB_HEIGHT - 1);
    }
    putonxy(201, mb->x, mb->y);
    putonxy(187, mb->x + GUI_MB_WIDTH - 1, mb->y);
    putonxy(200, mb->x, mb->y + GUI_MB_HEIGHT - 1);
    putonxy(188, mb->x + GUI_MB_WIDTH - 1, mb->y + GUI_MB_HEIGHT - 1);

    gotoxy(mb->x + 1, mb->y + 1);
    cprintf("%s", mb->text);

    redrawDButton(&mb->bt_yes, mb->x + 1, mb->y + GUI_MB_HEIGHT - 2);
    redrawDButton(&mb->bt_cancel, mb->x + GUI_MB_WIDTH / 2 - GUI_BUTTON_SIZE / 2, mb->y + GUI_MB_HEIGHT - 2);
    redrawDButton(&mb->bt_no, mb->x + GUI_MB_WIDTH - GUI_BUTTON_SIZE - 1, mb->y + GUI_MB_HEIGHT - 2);

    resetcolors();
}
