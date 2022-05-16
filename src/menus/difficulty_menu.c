/*
** EPITECH PROJECT, 2022
** difficulty_menu
** File description:
** functions used to choose the difficulty of the game
*/

#include "defender.h"

void display_difficulty_menu(defender *objects)
{
    display_background(objects->window, "src/images/blurry_tropico.png");
    display_buttons(objects->window, objects->play_menu_buttons);
    display_buttons(objects->window, objects->dif_menu_buttons);
}
