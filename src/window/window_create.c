/*
** EPITECH PROJECT, 2021
** window_create
** File description:
** create window
*/

#include <stdlib.h>
#include "defender.h"

void display_background(sfRenderWindow *win, char *background)
{
    sfTexture *texture = sfTexture_createFromFile(background,
    NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

sfRenderWindow *window_create(int x, int y, int framerate)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {x, y, 32};

    window = sfRenderWindow_create(video_mode, "My defender", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, framerate);
    return window;
}
