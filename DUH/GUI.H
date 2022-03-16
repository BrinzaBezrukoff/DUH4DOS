#ifndef __DUH_GUI_H
#define __DUH_GUI_H

#include "DUH/TOOLS.H"

#define GUI_TEXT_SIZE 64
#define GUI_BUTTON_SIZE 8

#define GUI_MB_WIDTH 34
#define GUI_MB_HEIGHT 5


typedef struct DButton {
    char text[GUI_BUTTON_SIZE];
    int ret_code;
    bool active;
} DButton;


typedef struct DMessageBox {
    uint x;
    uint y;
    char text[GUI_TEXT_SIZE];
    DButton bt_cancel;
    DButton bt_yes;
    DButton bt_no;
} DMessageBox;


DButton getDButton(char title[GUI_BUTTON_SIZE],
                   int ret_code);
void redrawDButton(DButton *button);

void initDMessageBox(DMessageBox *mb,
                     uint x,
                     uint y,
                     char text[GUI_TEXT_SIZE],
                     DButton bt_cancel,
                     DButton bt_yes,
                     DButton bt_no);
void redrawDMessageBox(DMessageBox *mb);


#endif
