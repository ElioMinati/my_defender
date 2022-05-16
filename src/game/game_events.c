/*
** EPITECH PROJECT, 2022
** game_events
** File description:
** functions used to analyse game events
*/

#include "defender.h"

void detect_game_button_hovering(defender *objects)
{
    if (is_button_hovered(objects->game->buttons[0],
    objects->window, 70, 70) == 1)
        objects->game->buttons[0].is_hover = 1;
    else
        objects->game->buttons[0].is_hover = 0;
    if (is_button_hovered(objects->game->buttons[1],
    objects->window, 70, 70) == 1)
        objects->game->buttons[1].is_hover = 1;
    else
        objects->game->buttons[1].is_hover = 0;
}

void detect_game_button_pressing(defender *objects)
{
    if (is_button_pressed(objects->game->buttons[0],
    objects, 70, 70) == 1 || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        objects->game->buttons[0].is_pressed = 1;
        objects->is_pause = 1;
    } else
        objects->game->buttons[0].is_pressed = 0;
    if (is_button_pressed(objects->game->buttons[1],
    objects, 85, 85) == 1 && is_round_over(objects->game) == 1) {
        objects->game->buttons[1].is_pressed = 1;
        objects->game->current_round += 1;
        handle_rounds(objects->game);
    } else
        objects->game->buttons[1].is_pressed = 0;
}

void detect_pause_button_hovering(defender *objects)
{
    if (is_button_hovered(objects->game->pause_buttons[0],
    objects->window, 70, 70) == 1)
        objects->game->pause_buttons[0].is_hover = 1;
    else
        objects->game->pause_buttons[0].is_hover = 0;
    if (is_button_hovered(objects->game->pause_buttons[1],
    objects->window, 150, 150) == 1)
        objects->game->pause_buttons[1].is_hover = 1;
    else
        objects->game->pause_buttons[1].is_hover = 0;
    if (is_button_hovered(objects->game->pause_buttons[2],
    objects->window, 70, 70) == 1)
        objects->game->pause_buttons[2].is_hover = 1;
    else
        objects->game->pause_buttons[2].is_hover = 0;
}

void detect_pause_button_pressing(defender *objects)
{
    if (is_button_pressed(objects->game->pause_buttons[0],
    objects, 70, 70) == 1) {
        objects->game->pause_buttons[0].is_pressed = 1;
        objects->is_pause = 0;
    } else
        objects->game->pause_buttons[0].is_pressed = 0;
    if (is_button_pressed(objects->game->pause_buttons[1],
    objects, 150, 150) == 1) {
        objects->game->pause_buttons[1].is_pressed = 1;
        objects->is_in_game = 0;
        objects->is_pause = 0;
        objects->is_main_menu = 1;
    } else
        objects->game->pause_buttons[1].is_pressed = 0;
    if (is_button_pressed(objects->game->pause_buttons[2],
    objects, 70, 70) == 1) {
        objects->game->pause_buttons[2].is_pressed = 1;
        objects->is_exit = 1;
    } else
        objects->game->pause_buttons[2].is_pressed = 0;
}
