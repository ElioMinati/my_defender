/*
** EPITECH PROJECT, 2022
** detect_game_end.c
** File description:
** functions used to detect if the game has ended
*/

#include "defender.h"

void detect_lose_button_hovering(defender *objects)
{
    if (is_button_hovered(objects->game->lose_buttons[0],
    objects->window, 140, 140) == 1)
        objects->game->lose_buttons[0].is_hover = 1;
    else
        objects->game->lose_buttons[0].is_hover = 0;
}

void detect_lose_button_pressing(defender *objects)
{
    if (is_button_pressed(objects->game->lose_buttons[0],
    objects, 140, 140) == 1) {
        objects->game->lose_buttons[0].is_pressed = 1;
        objects->is_in_game = 0;
        objects->is_main_menu = 1;
        destroy_game(objects);
        objects->is_lose = 0;
    } else
        objects->game->lose_buttons[0].is_pressed = 0;
}

void detect_win_button_hovering(defender *objects)
{
    if (is_button_hovered(objects->game->win_buttons[0],
    objects->window, 140, 140) == 1)
        objects->game->win_buttons[0].is_hover = 1;
    else
        objects->game->win_buttons[0].is_hover = 0;
    if (is_button_hovered(objects->game->win_buttons[1],
    objects->window, 140, 140) == 1)
        objects->game->win_buttons[1].is_hover = 1;
    else
        objects->game->win_buttons[1].is_hover = 0;
}

void detect_win_button_pressing(defender *objects)
{
    if (is_button_pressed(objects->game->win_buttons[0],
    objects, 140, 140) == 1) {
        objects->game->win_buttons[0].is_pressed = 1;
        objects->is_in_game = 0;
        objects->is_main_menu = 1;
        destroy_game(objects);
        objects->is_win = 0;
    } else
        objects->game->win_buttons[0].is_pressed = 0;
    if (is_button_pressed(objects->game->win_buttons[1],
    objects, 140, 140) == 1) {
        objects->game->win_buttons[1].is_pressed = 1;
        objects->game->is_infinite = 1;
        objects->is_win = 0;
    } else
        objects->game->win_buttons[1].is_pressed = 0;
}

void detect_game_end(defender *objects)
{
    if (objects->game->lives <= 0 && objects->is_lose == 0) {
        sfMusic_play(objects->game->lose);
        objects->is_lose = 1;
    }
    if (objects->game->current_round == objects->game->rounds &&
    is_round_over(objects->game) && objects->game->is_infinite == 0 &&
    objects->is_win == 0) {
        objects->is_win = 1;
        sfMusic_play(objects->game->win);
    }
}
