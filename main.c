#include <gb/gb.h>
#include "alpha.c"
#include "hello_world.c"
#include "blank_screen.c"
#include "player_sprite.c"

void main();
void init();
void checkInput();
void updateSwitches();
void drawPlayer();

UINT8 playerPosition[2];

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
    set_bkg_tiles(0, 0, 20, 18, blankScreen);
    set_bkg_tiles(5, 17, 11, 1, helloWorld);

    set_sprite_data(0, 4, player_sprite);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 1);
    set_sprite_tile(2, 2);
    set_sprite_tile(3, 3);

    playerPosition[0] = 80;
    playerPosition[1] = 72;

    drawPlayer();
}

void updateSwitches() {
    HIDE_WIN;
    SHOW_SPRITES;
    SHOW_BKG;
}

void checkInput() {
    if (joypad() & J_UP && playerPosition[1] > 16) {
		playerPosition[1]--;
	}

	if (joypad() & J_DOWN && playerPosition[1] < 136) {
		playerPosition[1]++;
	}

	if (joypad() & J_LEFT && playerPosition[0] > 8) {
		playerPosition[0]--;
	}	
	
	// RIGHT
	if (joypad() & J_RIGHT && playerPosition[0] < 152) {
		playerPosition[0]++;
	}

    drawPlayer();
}

void drawPlayer() {
    move_sprite(0, playerPosition[0], playerPosition[1]);
    move_sprite(1, playerPosition[0] + 8, playerPosition[1]);
    move_sprite(2, playerPosition[0], playerPosition[1] + 8);
    move_sprite(3, playerPosition[0] + 8, playerPosition[1] + 8);
}
