/*
** EPITECH PROJECT, 2022
** display_game.c
** File description:
** functions used to display the game on screen
*/

#include <stdlib.h>
#include "my.h"
#include "defender.h"

void display_towers(sfRenderWindow *win, tower *towers)
{
    for (int i = towers->nb_towers - 1; i >= 0; --i) {
        sfRenderWindow_drawSprite(win, towers[i].sprite, NULL);
    }
}

void display_game_info(defender *objects)
{
    display_buttons(objects->window, objects->game->buttons);
    display_money(objects->window, objects->game, objects);
    display_rounds(objects->window, objects->game, objects);
    display_lives(objects->window, objects->game, objects->cr_font);
}

void display_tower_drop(defender *objects)
{
    if (objects->game->card_id == 1 && objects->game->money >= 450) {
        display_radius(objects, 200);
        display_tesla(objects);
        detect_drop(objects, 1, 450);
    }
    if (objects->game->card_id == 2 && objects->game->money >= 600) {
        display_radius(objects, 125);
        display_tac(objects);
        detect_drop(objects, 2, 600);
    }
    if (objects->game->card_id == 3 && objects->game->money >= 1150) {
        display_radius(objects, 75);
        display_sauda(objects);
        detect_drop(objects, 3, 1150);
    }
    if (objects->game->card_id == 4 && objects->game->money >= 350) {
        display_radius(objects, 80);
        display_sniper(objects);
        detect_drop(objects, 4, 350);
    }
}

void display_ig_menus(defender *objects)
{
    if (objects->game->towers != NULL)
        display_towers(objects->window, objects->game->towers);
    display_bloons(objects);
    sfRenderWindow_drawSprite(objects->window,
    objects->game->sidebar_sprite, sfFalse);
    display_buttons(objects->window, objects->game->cards);
    display_prices(objects, objects->cr_font);
    if (objects->is_pause == 1) {
        sfRenderWindow_drawSprite(objects->window,
        objects->game->pause_sprite, sfFalse);
        display_buttons(objects->window, objects->game->pause_buttons);
    } else if (objects->is_win == 0 && objects->is_lose == 0) {
        if (objects->game->card_id > 0)
            display_tower_drop(objects);
        display_game_info(objects);
        display_upgrade_menu(objects);
    } else
        display_end_menu(objects);
}

void display_vgame(defender *objects)
{
    sfRenderWindow_drawSprite(objects->window,
    objects->game->map_sprite, sfFalse);
    display_ig_menus(objects);
    detect_game_end(objects);
}
