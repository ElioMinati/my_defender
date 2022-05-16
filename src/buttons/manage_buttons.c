/*
** EPITECH PROJECT, 2022
** manage_buttons.c
** File description:
** functions used to manage buttons
*/

#include "defender.h"

int is_button_hovered(buttons button, sfRenderWindow *win,
int width, int height)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);

    if (mouse.x > button.pos.x && mouse.x < (button.pos.x + width)) {
        if (mouse.y > button.pos.y && mouse.y < (button.pos.y + height)) {
            return 1;
        }
    }
    return 0;
}

int is_button_pressed(buttons button, defender *objects,
int width, int height)
{
    int x = objects->event.mouseButton.x;
    int y = objects->event.mouseButton.y;

    if (x > button.pos.x && x < (button.pos.x + width) &&
    objects->event.type == sfEvtMouseButtonPressed) {
        if (y > button.pos.y && y < (button.pos.y + height)) {
            objects->event.type = sfEvtMouseButtonReleased;
            return 1;
        }
    }
    return 0;
}

int is_case_hovered(map_case map_case, sfRenderWindow *win,
int width, int height)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);

    if (mouse.x > map_case.pos.x && mouse.x < (map_case.pos.x + width)) {
        if (mouse.y > map_case.pos.y && mouse.y < (map_case.pos.y + height)) {
            return 1;
        }
    }
    return 0;
}

int is_case_pressed(map_case map_case, defender *objects,
int width, int height)
{
    int x = objects->event.mouseButton.x;
    int y = objects->event.mouseButton.y;

    if (x > map_case.pos.x && x < (map_case.pos.x + width) &&
    objects->event.type == sfEvtMouseButtonPressed) {
        if (y > map_case.pos.y && y < (map_case.pos.y + height)) {
            objects->event.type = sfEvtMouseButtonReleased;
            return 1;
        }
    }
    return 0;
}
