#include <gb/gb.h>
#include <string.h>
#include "alpha.c"
#include "hello_world.c"
#include "blank_screen.c"
#include "player_sprite.c"
#include "player_direction.c"

void main();
void init();
void checkInput();
void updateSwitches();
void drawPlayer();

UINT8 playerPosition[2];
enum PlayerDirection playerDirection = Down;

void main() 
{
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

    set_sprite_data(0, 16, player_sprite);

    set_sprite_tile(0, player_down_tile[0]);
    set_sprite_tile(1, player_down_tile[1]);
    set_sprite_tile(2, player_down_tile[2]);
    set_sprite_tile(3, player_down_tile[3]);

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
    if (joypad() & J_UP && playerPosition[1] > 16) 
    {
		playerPosition[1]--;
        playerDirection = Up;
	}

	if (joypad() & J_DOWN && playerPosition[1] < 136) 
    {
		playerPosition[1]++;
        playerDirection = Down;
	}

	if (joypad() & J_LEFT && playerPosition[0] > 8) 
    {
		playerPosition[0]--;
        playerDirection = Left;
	}	
	
	if (joypad() & J_RIGHT && playerPosition[0] < 152) 
    {
		playerPosition[0]++;
        playerDirection = Right;
	}

    drawPlayer();
}

void drawPlayer() {

    UINT8 player_dir[4];

    switch (playerDirection)
    {
        case Up:
            memcpy(player_dir, player_up_tile, sizeof player_dir);
            break;
        case Right:
            memcpy(player_dir, player_right_tile, sizeof player_dir);
            break;
        case Down:
            memcpy(player_dir, player_down_tile, sizeof player_dir);
            break;
        case Left:
            memcpy(player_dir, player_left_tile, sizeof player_dir);
            break;
    }

    set_sprite_tile(0, player_dir[0]);
    set_sprite_tile(1, player_dir[1]);
    set_sprite_tile(2, player_dir[2]);
    set_sprite_tile(3, player_dir[3]);

    move_sprite(0, playerPosition[0], playerPosition[1]);
    move_sprite(1, playerPosition[0] + 8, playerPosition[1]);
    move_sprite(2, playerPosition[0], playerPosition[1] + 8);
    move_sprite(3, playerPosition[0] + 8, playerPosition[1] + 8);
}
