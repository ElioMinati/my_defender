/*
** EPITECH PROJECT, 2022
** display_lives
** File description:
** functions used to display the lives we have left
*/

#include "my.h"
#include "defender.h"

void display_lives(sfRenderWindow *win, game *game, sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos_text = {80, 35};

    sfText_setString(text, my_int_to_str(game->lives));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 25);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos_text);
    sfText_setOutlineThickness(text, 3);
    sfRenderWindow_drawText(win, text, NULL);
    sfRenderWindow_drawSprite(win, game->heart_sprite, NULL);
    sfText_destroy(text);
}