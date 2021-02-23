#include <gb/gb.h>
#include "alpha.c"
#include "hello_world.c"
#include "blank_screen.c"

void main();
void init();
void checkInput();
void updateSwitches();

void main() {
    init();

    while (1) {
        checkInput();
        updateSwitches();
        wait_vbl_done();
    }
}

void init() {
    DISPLAY_ON;
    set_bkg_data(0, 47, alpha);
    set_bkg_tiles(0,0,20,18,blankScreen);
    set_bkg_tiles(0,6,10,2,helloWorld);
}

void updateSwitches() {
    HIDE_WIN;
    SHOW_SPRITES;
    SHOW_BKG;
}

void checkInput() {
    if (joypad() && J_B) {

    }
}
