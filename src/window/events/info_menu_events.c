/*
** EPITECH PROJECT, 2022
** info_menu_events.c
** File description:
** functions used to handle info menu events
*/

#include "defender.h"

void detect_imenu_button_pressing(defender *objects)
{
    if (is_button_pressed(objects->play_menu_buttons[0],
    objects, 70, 70) == 1) {
        objects->play_menu_buttons[0].is_pressed = 1;
        objects->is_exit = 1;
    } else
        objects->play_menu_buttons[0].is_pressed = 0;
    if (is_button_pressed(objects->play_menu_buttons[1],
    objects, 70, 70) == 1) {
        objects->play_menu_buttons[1].is_pressed = 1;
        objects->is_info_menu = 0;
        objects->is_main_menu = 1;
    } else
        objects->play_menu_buttons[1].is_pressed = 0;
}
