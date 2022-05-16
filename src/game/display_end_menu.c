/*
** EPITECH PROJECT, 2022
** display_end_menu
** File description:
** functions used to display win / lose menu
*/


#include <stdlib.h>
#include "defender.h"

static void create_end_menu_buttons(game *game)
{
    sfVector2f pos = {730, 680};
    sfVector2f pos1 = {730, 680};
    sfVector2f f_pos = {900, 680};

    game->lose_buttons->nb_buttons = 1;
    game->win_buttons->nb_buttons = 2;
    create_home_button(game->lose_buttons, pos, 1, 0);
    create_home_button(game->win_buttons, pos1, 1, 0);
    create_freeplay_button(game->win_buttons, f_pos, 1, 1);
}

void init_end_menu(game *game)
{
    sfVector2f pos = {400, 200};

    game->lose_texture = sfTexture_createFromFile("src/images/defeat.png",
    NULL);
    game->lose_sprite = sfSprite_create();
    sfSprite_setTexture(game->lose_sprite,
    game->lose_texture, sfFalse);
    sfSprite_setPosition(game->lose_sprite, pos);
    game->win_texture = sfTexture_createFromFile("src/images/victory.png",
    NULL);
    game->win_sprite = sfSprite_create();
    sfSprite_setTexture(game->win_sprite,
    game->win_texture, sfFalse);
    sfSprite_setPosition(game->win_sprite, pos);
    game->win_buttons = malloc(2 * sizeof(buttons));
    game->lose_buttons = malloc(1 * sizeof(buttons));
    create_end_menu_buttons(game);
}

void display_end_menu(defender *objects)
{
    if (objects->is_lose == 1) {
        sfRenderWindow_drawSprite(objects->window,
        objects->game->lose_sprite, NULL);
        display_buttons(objects->window, objects->game->lose_buttons);
    }
    if (objects->is_win == 1) {
        sfRenderWindow_drawSprite(objects->window,
        objects->game->win_sprite, NULL);
        display_buttons(objects->window, objects->game->win_buttons);
    }
}
