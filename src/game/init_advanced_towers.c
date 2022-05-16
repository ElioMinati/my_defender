/*
** EPITECH PROJECT, 2022
** init_advanced_towers.c
** File description:
** initialise values for the advanced towers
*/

#include <stdlib.h>
#include "defender.h"

void init_sauda(game *game, int index, sfVector2f pos)
{
    sfVector2f offset = {125, 90};

    game->towers[index].id = game->card_id;
    game->towers[index].pos = pos;
    game->towers[index].offset = offset;
    game->towers[index].resize = 1;
    game->towers[index].price = 1150;
    game->towers[index].rad = 80;
    game->towers[index].level = 1;
    game->towers[index].rad_level = 1;
    game->towers[index].upgrade_prices = malloc(3 * sizeof(int));
    game->towers[index].upgrade_prices[0] = 1650;
    game->towers[index].upgrade_prices[1] = 3700;
    game->towers[index].upgrade_prices[2] = 5500;
    game->towers[index].radius_up_prices = malloc(3 * sizeof(int));
    game->towers[index].radius_up_prices[0] = 550;
    game->towers[index].radius_up_prices[1] = 1700;
    game->towers[index].radius_up_prices[2] = 3000;
    game->towers[index].cooldown = sfClock_create();
    game->towers[index].cool_time = 0.5;
}

void init_sniper(game *game, int index, sfVector2f pos)
{
    sfVector2f offset = {90, 68};

    game->towers[index].id = game->card_id;
    game->towers[index].pos = pos;
    game->towers[index].offset = offset;
    game->towers[index].resize = 1;
    game->towers[index].price = 350;
    game->towers[index].rad = 90;
    game->towers[index].level = 1;
    game->towers[index].rad_level = 1;
    game->towers[index].upgrade_prices = malloc(3 * sizeof(int));
    game->towers[index].upgrade_prices[0] = 450;
    game->towers[index].upgrade_prices[1] = 1900;
    game->towers[index].upgrade_prices[2] = 6700;
    game->towers[index].radius_up_prices = malloc(3 * sizeof(int));
    game->towers[index].radius_up_prices[0] = 0;
    game->towers[index].radius_up_prices[1] = 0;
    game->towers[index].radius_up_prices[2] = 0;
    game->towers[index].cooldown = sfClock_create();
    game->towers[index].cool_time = 1.3;
}
