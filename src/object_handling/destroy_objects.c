/*
** EPITECH PROJECT, 2022
** destroy_objects.c
** File description:
** functions used to free & destroy used memory
*/

#include <stdlib.h>
#include "defender.h"

void destroy_struct(defender *objects) {
    sfFont_destroy(objects->btd_font);
    sfFont_destroy(objects->cr_font);
    sfClock_destroy(objects->clock);
    sfTexture_destroy(objects->menu_buttons[0].texture);
    sfTexture_destroy(objects->menu_buttons[1].texture);
    sfTexture_destroy(objects->menu_buttons[2].texture);
    sfSprite_destroy(objects->menu_buttons[0].sprite);
    sfSprite_destroy(objects->menu_buttons[1].sprite);
    sfSprite_destroy(objects->menu_buttons[2].sprite);
    sfRenderWindow_destroy(objects->window);
    sfMusic_destroy(objects->bg_music);
    if (objects->did_game == 1)
        destroy_game(objects);
    free(objects);
}

void destroy_game(defender *objects)
{
    sfMusic_destroy(objects->game->lose);
    sfMusic_destroy(objects->game->win);
}
