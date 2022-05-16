/*
** EPITECH PROJECT, 2022
** main_menu_events.c
** File description:
** functions used to handle events in the main menu
*/

#include "defender.h"

void detect_menu_button_hovering(defender *objects)
{
    if (is_button_hovered(objects->menu_buttons[0],
    objects->window, 70, 70) == 1)
        objects->menu_buttons[0].is_hover = 1;
    else
        objects->menu_buttons[0].is_hover = 0;
    if (is_button_hovered(objects->menu_buttons[1],
    objects->window, 400, 205) == 1)
        objects->menu_buttons[1].is_hover = 1;
    else
        objects->menu_buttons[1].is_hover = 0;
    if (is_button_hovered(objects->menu_buttons[2],
    objects->window, 90, 80) == 1)
        objects->menu_buttons[2].is_hover = 1;
    else
        objects->menu_buttons[2].is_hover = 0;
}

void detect_menu_button_pressing(defender *objects)
{
    if (is_button_pressed(objects->menu_buttons[0],
    objects, 70, 70) == 1) {
        objects->menu_buttons[0].is_pressed = 1;
        objects->is_exit = 1;
    } else
        objects->menu_buttons[0].is_pressed = 0;
    if (is_button_pressed(objects->menu_buttons[1],
    objects, 400, 205) == 1) {
        objects->menu_buttons[1].is_pressed = 1;
        objects->is_main_menu = 0;
        objects->is_play_menu = 1;
    } else
        objects->menu_buttons[1].is_pressed = 0;
    if (is_button_pressed(objects->menu_buttons[2],
    objects, 90, 80) == 1) {
        objects->menu_buttons[2].is_pressed = 1;
        objects->is_main_menu = 0;
        objects->is_info_menu = 1;
    } else
        objects->menu_buttons[2].is_pressed = 0;
}
