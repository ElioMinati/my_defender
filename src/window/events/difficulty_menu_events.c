/*
** EPITECH PROJECT, 2022
** difficulty_menu_events
** File description:
** functions used to manage events in the dif menu
*/

#include "defender.h"

void detect_cmenu_button_hovering(defender *objects)
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

void detect_cmenu_button_pressing(defender *objects)
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
        objects->is_dif_choice = 0;
        objects->is_play_menu = 1;
    } else
        objects->play_menu_buttons[1].is_pressed = 0;
}

void detect_hard_dif_choice(defender *objects)
{
    if (is_button_pressed(objects->dif_menu_buttons[2],
    objects, 400, 205) == 1) {
        objects->dif_menu_buttons[2].is_pressed = 1;
        objects->is_in_game = 1;
        objects->is_dif_choice = 0;
        objects->game->mode = hard;
        init_game(objects);
    } else
        objects->dif_menu_buttons[2].is_pressed = 0;
}

void detect_difficulty_hover(defender *objects)
{
    if (is_button_hovered(objects->dif_menu_buttons[0],
    objects->window, 400, 205) == 1) {
        objects->dif_menu_buttons[0].is_hover = 1;
    } else
        objects->dif_menu_buttons[0].is_hover = 0;
    if (is_button_hovered(objects->dif_menu_buttons[1],
    objects->window, 400, 205) == 1) {
        objects->dif_menu_buttons[1].is_hover = 1;
    } else
        objects->dif_menu_buttons[1].is_hover = 0;
    if (is_button_hovered(objects->dif_menu_buttons[2],
    objects->window, 400, 205) == 1) {
        objects->dif_menu_buttons[2].is_hover = 1;
    } else
        objects->dif_menu_buttons[2].is_hover = 0;
}

void detect_difficulty_choice(defender *objects)
{
    if (is_button_pressed(objects->dif_menu_buttons[0],
    objects, 400, 205) == 1) {
        objects->dif_menu_buttons[0].is_pressed = 1;
        objects->is_in_game = 1;
        objects->is_dif_choice = 0;
        objects->game->mode = easy;
        init_game(objects);
    } else
        objects->dif_menu_buttons[0].is_pressed = 0;
    if (is_button_pressed(objects->dif_menu_buttons[1],
    objects, 400, 205) == 1) {
        objects->dif_menu_buttons[1].is_pressed = 1;
        objects->is_in_game = 1;
        objects->is_dif_choice = 0;
        objects->game->mode = medium;
        init_game(objects);
    } else
        objects->dif_menu_buttons[1].is_pressed = 0;
    detect_hard_dif_choice(objects);
}
