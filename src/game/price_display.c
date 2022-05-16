/*
** EPITECH PROJECT, 2022
** price_display.c
** File description:
** functions used to display the card price
*/

#include <stdlib.h>
#include "my.h"
#include "defender.h"

void display_money(sfRenderWindow *win, game *game, defender *objects)
{
    sfText *text = sfText_create();
    sfVector2f pos_text = {220, 35};

    sfText_setString(text, my_int_to_str(game->money));
    sfText_setFont(text, objects->cr_font);
    sfText_setColor(text, sfBlue);
    sfText_setCharacterSize(text, 25);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos_text);
    sfText_setOutlineThickness(text, 3);
    sfRenderWindow_drawSprite(win, game->gold_sprite, sfFalse);
    sfRenderWindow_drawText(objects->window, text, NULL);
    sfText_destroy(text);
}

void display_price(defender *objects, sfVector2f pos, sfFont *font,
int price)
{
    sfText *text = sfText_create();

    sfText_setString(text, my_int_to_str(price));
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlue);
    sfText_setCharacterSize(text, 20);
    if (price > objects->game->money)
        sfText_setFillColor(text, sfRed);
    else
        sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos);
    sfText_setOutlineThickness(text, 5);
    sfRenderWindow_drawText(objects->window, text, NULL);
    sfText_destroy(text);
}

void display_prices(defender *objects, sfFont *font)
{
    sfVector2f pos = {1660, 270};
    sfVector2f pos1 = {1798, 270};

    display_price(objects, pos, font, 450);
    display_price(objects, pos1, font, 600);
}

void display_rounds(sfRenderWindow *win, game *game, defender *objects)
{
    char *str = malloc(6 * sizeof(char));
    sfText *text = sfText_create();
    sfVector2f pos = {1360, 40};

    str = my_strconcat(my_int_to_str(game->current_round), "\\");
    str = my_strconcat(str, my_int_to_str(game->rounds));

    if (game->is_infinite == 1)
        str = my_int_to_str(game->current_round);
    sfText_setString(text, str);
    sfText_setFont(text, objects->cr_font);
    sfText_setColor(text, sfBlue);
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos);
    sfText_setOutlineThickness(text, 5);
    sfRenderWindow_drawText(win, text, NULL);
    sfText_destroy(text);
}
