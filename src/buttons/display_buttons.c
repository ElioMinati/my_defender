/*
** EPITECH PROJECT, 2022
** buttons.c
** File description:
** create a button
*/

#include "defender.h"

void display_buttons(sfRenderWindow *win, buttons *buttons)
{
    for (int i = 0; i < buttons->nb_buttons; ++i) {
        if (buttons[i].is_hover == 1 &&
        buttons[i].is_pressed == 0) {
            sfRenderWindow_drawSprite(win, buttons[i].hovered_sprite, NULL);
        } else if (buttons[i].is_pressed == 1) {
            sfRenderWindow_drawSprite(win, buttons[i].pressed_sprite, NULL);
        } else {
            sfRenderWindow_drawSprite(win, buttons[i].sprite, NULL);
        }
    }
}
