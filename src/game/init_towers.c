/*
** EPITECH PROJECT, 2022
** init_towers.c
** File description:
** functions used to initialize towers for the defender
*/

#include <math.h>
#include <stdlib.h>
#include "defender.h"

void init_cards(buttons *cards)
{
    sfVector2f tesla_pos = {1627, 160};
    sfVector2f tac_pos = {1770, 162};
    sfVector2f sauda_pos = {1627, 320};
    sfVector2f sniper_pos = {1770, 320};

    cards->nb_buttons = 4;
    create_tesla_button(cards, tesla_pos, 0.47, 0);
    create_tac_button(cards, tac_pos, 0.442, 1);
    create_sauda_button(cards, sauda_pos, 0.442, 2);
    create_sniper_button(cards, sniper_pos, 0.442, 3);
}

void init_tac(game *game, int index, sfVector2f pos)
{
    sfVector2f offset = {55, 80};

    game->towers[index].id = game->card_id;
    game->towers[index].pos = pos;
    game->towers[index].offset = offset;
    game->towers[index].resize = 1;
    game->towers[index].price = 600;
    game->towers[index].rad = 125;
    game->towers[index].level = 1;
    game->towers[index].rad_level = 1;
    game->towers[index].upgrade_prices = malloc(3 * sizeof(int));
    game->towers[index].upgrade_prices[0] = 800;
    game->towers[index].upgrade_prices[1] = 2200;
    game->towers[index].upgrade_prices[2] = 4500;
    game->towers[index].radius_up_prices = malloc(3 * sizeof(int));
    game->towers[index].radius_up_prices[0] = 125;
    game->towers[index].radius_up_prices[1] = 600;
    game->towers[index].radius_up_prices[2] = 1300;
    game->towers[index].cooldown = sfClock_create();
    game->towers[index].cool_time = 1;
}

void init_tesla(game *game, int index, sfVector2f pos)
{
    sfVector2f offset = {37, 130};

    game->towers[index].id = game->card_id;
    game->towers[index].pos = pos;
    game->towers[index].offset = offset;
    game->towers[index].resize = 1.2;
    game->towers[index].price = 450;
    game->towers[index].rad = 200;
    game->towers[index].level = 1;
    game->towers[index].rad_level = 1;
    game->towers[index].upgrade_prices = malloc(3 * sizeof(int));
    game->towers[index].upgrade_prices[0] = 750;
    game->towers[index].upgrade_prices[1] = 1800;
    game->towers[index].upgrade_prices[2] = 3500;
    game->towers[index].radius_up_prices = malloc(3 * sizeof(int));
    game->towers[index].radius_up_prices[0] = 250;
    game->towers[index].radius_up_prices[1] = 800;
    game->towers[index].radius_up_prices[2] = 1250;
    game->towers[index].cooldown = sfClock_create();
    game->towers[index].cool_time = 0.6;
}

void init_shoot_angle(bloon bloon, tower *towers, int i, sfVector2f v)
{
    sfVector2f b_pos = sfCircleShape_getPosition(bloon.hitbox);
    sfVector2f t_pos = {towers[i].pos.x + towers[i].offset.x,
    towers[i].pos.y + 15};
    sfVector2f u = {b_pos.x - t_pos.x, b_pos.y - t_pos.y};

    float dot = (u.x * v.x + u.y * v.y);
    double cross = (u.x * v.y - u.y * v.x);
    towers[i].angle = atan2f((float)fabs(cross), dot) * 180 / M_PI;

    if (cross < 0)
        towers[i].angle = 360 - towers[i].angle;
    towers[i].angle = 360 - towers[i].angle;
}
