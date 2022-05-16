/*
** EPITECH PROJECT, 2022
** upgrade_handling
** File description:
** functions used to handle the upgrades
*/

#include "defender.h"

static void rad_upgrade_handling(defender *objects, tower *towers,
int i, int j)
{
    if (towers[i].upgrade_buttons[j].button_type == radius_up &&
    towers[i].rad_level < 4 && objects->game->money >=
    towers[i].radius_up_prices[towers[i].rad_level - 1] &&
    is_button_pressed(towers[i].upgrade_buttons[j], objects, 348, 145)) {
        if (towers[i].id == 1)
            towers[i].rad += 50;
        if (towers[i].id == 2)
            towers[i].rad += 15;
        objects->game->money -=
        towers[i].radius_up_prices[towers[i].rad_level - 1];
        towers[i].rad_level++;
    }
}

static void upgrade_tower(tower *towers, int i)
{
    if (towers[i].id == 1) {
        towers[i].rect.left += 75;
    }
    if (towers[i].id == 2) {
        towers[i].rect.left += 108;
    }
    if (towers[i].id == 4) {
        towers[i].rect.left += 140;
        if (towers[i].level == 2)
            towers[i].cool_time = 1;
        if (towers[i].level == 3)
            towers[i].damage = 4;
    }
    if (towers[i].id == 4 && towers[i].level == 4)
        towers[i].cool_time = 0.2;
    if (towers[i].level % 2 == 0 && towers[i].id != 4)
        towers[i].damage += 1;
    if (towers[i].level == 3 && towers[i].id != 4)
        towers[i].cool_time -= 0.3;
}

void upgrade_handling(defender *objects, tower *towers, int i, int j)
{
    rad_upgrade_handling(objects, towers, i, j);
    if (is_button_pressed(towers[i].upgrade_buttons[j], objects, 348, 145) &&
    towers[i].level < 4 && objects->game->money >=
    towers[i].upgrade_prices[towers[i].level - 1] &&
    towers[i].upgrade_buttons[j].button_type == upgrade) {
        objects->game->money -= towers[i].upgrade_prices[towers[i].level - 1];
        towers[i].level++;
        upgrade_tower(towers, i);
        sfSprite_setTextureRect(towers[i].sprite, towers[i].rect);
    }
}