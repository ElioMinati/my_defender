/*
** EPITECH PROJECT, 2022
** play_menu.c
** File description:
** functions used to display the play menu
*/

#include "defender.h"

static void display_cases(sfRenderWindow *win, map_case *cases)
{
    for (int i = 0; i < cases->nb_cases; ++i) {
        sfRenderWindow_drawSprite(win, cases[i].map_sprite, sfFalse);
        sfRenderWindow_drawSprite(win, cases[i].sprite, sfFalse);
    }
}

void display_play_menu(defender *objects)
{
    display_background(objects->window, "src/images/blurry_tropico.png");
    display_buttons(objects->window, objects->play_menu_buttons);
    display_cases(objects->window, objects->map_case);
}
