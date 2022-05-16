/*
** EPITECH PROJECT, 2022
** card_events.c
** File description:
** functions used to detect card events
*/

#include "defender.h"

void detect_game_card_hovering(defender *objects)
{
    for (int i = 0; i < objects->game->cards->nb_buttons; ++i) {
        if (is_button_hovered(objects->game->cards[i],
        objects->window, 120, 145) == 1)
            objects->game->cards[i].is_hover = 1;
        else
            objects->game->cards[i].is_hover = 0;
    }
}

void detect_game_card_pressing(defender *objects)
{
    for (int i = 0; i < objects->game->cards->nb_buttons; ++i) {
        if (is_button_pressed(objects->game->cards[i],
        objects, 120, 145) == 1) {
            objects->game->cards[i].is_pressed = 1;
            objects->game->card_id = i + 1;
        } else
            objects->game->cards[i].is_pressed = 0;
    }
}
