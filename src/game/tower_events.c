/*
** EPITECH PROJECT, 2022
** tower_events.c
** File description:
** functions used to handle the events on towers
*/

#include "defender.h"

void detect_tower_pressing(tower *towers, defender *objects)
{
    if (towers == NULL)
        return;
    for (int i = 0; i < towers->nb_towers; ++i) {
        if (is_button_pressed(towers[i].button, objects,
        towers[i].button.width, towers[i].button.height)) {
            objects->is_upgrade = 1;
            objects->game->tower_to_upgrade = i;
        }
    }
    if (is_button_pressed(objects->game->upgrade_buttons[0],
    objects, 70, 70) == 1 && objects->is_upgrade == 1) {
        objects->is_upgrade = 0;
        objects->game->tower_to_upgrade = -1;
    }
}

static void hover_handling(defender *objects, int i, int j)
{
    if (is_button_hovered(objects->game->towers[i].upgrade_buttons[j],
    objects->window, 348, 145) == 1 &&
    objects->game->towers[i].upgrade_buttons[j].button_type == upgrade &&
    objects->game->towers[i].level < 4) {
        objects->game->towers[i].upgrade_buttons[j].is_hover = 1;
    } else if (is_button_hovered(objects->game->towers[i].upgrade_buttons[j],
    objects->window, 348, 145) == 1 &&
    objects->game->towers[i].upgrade_buttons[j].button_type == radius_up &&
    objects->game->towers[i].rad_level < 4) {
        objects->game->towers[i].upgrade_buttons[j].is_hover = 1;
    } else
        objects->game->towers[i].upgrade_buttons[j].is_hover = 0;
}

void detect_upgrade_button_hovering(defender *objects)
{
    for (int i = 0; i < objects->game->towers->nb_towers; ++i) {
        for (int j = 0;
        j < objects->game->towers[i].upgrade_buttons->nb_buttons; ++j) {
            hover_handling(objects, i, j);
        }
    }
}

void detect_upgrade_button_pressing(defender *objects)
{
    int i = objects->game->tower_to_upgrade;
    for (int j = 0;
    j < objects->game->towers[i].upgrade_buttons->nb_buttons; ++j) {
        upgrade_handling(objects, objects->game->towers, i, j);
    }
}
