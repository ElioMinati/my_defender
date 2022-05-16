/*
** EPITECH PROJECT, 2022
** play_menu_events.c
** File description:
** functions used to handle events in the play menu
*/

#include "defender.h"

void detect_pmenu_button_hovering(defender *objects)
{
    if (is_button_hovered(objects->play_menu_buttons[0],
    objects->window, 70, 70) == 1)
        objects->play_menu_buttons[0].is_hover = 1;
    else
        objects->play_menu_buttons[0].is_hover = 0;
    if (is_button_hovered(objects->play_menu_buttons[1],
    objects->window, 70, 70) == 1)
        objects->play_menu_buttons[1].is_hover = 1;
    else
        objects->play_menu_buttons[1].is_hover = 0;
}

void detect_pmenu_button_pressing(defender *objects)
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
        objects->is_play_menu = 0;
        objects->is_main_menu = 1;
    } else
        objects->play_menu_buttons[1].is_pressed = 0;
}

void detect_pmenu_case_hovering(defender *objects)
{
    sfVector2f upscale_map = {0.26, 0.29};
    sfVector2f upscale_case = {1.2, 1.2};
    sfVector2f downscale_map = {0.21, 0.23};
    sfVector2f downscale_case = {1, 1};


    for (int i = 0; i < objects->map_case->nb_cases; ++i) {
        if (is_case_hovered(objects->map_case[i], objects->window, 364, 283)) {
            objects->map_case[i].is_hover = 1;
            sfSprite_setScale(objects->map_case[i].sprite, upscale_case);
            sfSprite_setScale(objects->map_case[i].map_sprite, upscale_map);
        } else {
            objects->map_case[i].is_hover = 0;
            sfSprite_setScale(objects->map_case[i].sprite, downscale_case);
            sfSprite_setScale(objects->map_case[i].map_sprite, downscale_map);
        }

    }
}

void detect_pmenu_case_pressing(defender *objects)
{
    for (int i = 0; i < objects->map_case->nb_cases; ++i) {
        if (is_case_pressed(objects->map_case[i], objects, 364, 283)) {
            objects->map_case[i].is_pressed = 1;
            objects->map_choice = i + 1;
            objects->is_play_menu = 0;
            objects->is_dif_choice = 1;
        } else {
            objects->map_case[i].is_pressed = 0;
        }
    }
}