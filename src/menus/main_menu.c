/*
** EPITECH PROJECT, 2022
** main_menu.c
** File description:
** functions used to display main menu
*/

#include "defender.h"

static void display_main_text(defender *objects)
{
    sfText *text = sfText_create();
    sfVector2f pos_text = {300, 100};

    sfText_setString(text, "Bloons TD x Clash Royale");
    sfText_setFont(text, objects->btd_font);
    sfText_setColor(text, sfBlue);
    sfText_setCharacterSize(text, 100);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos_text);
    sfText_setOutlineThickness(text, 5);
    sfRenderWindow_drawText(objects->window, text, NULL);
    sfText_destroy(text);
}

void display_main_menu(defender *objects)
{
    display_background(objects->window, "src/images/tropico.jpg");
    display_main_text(objects);
    display_buttons(objects->window, objects->menu_buttons);
}
