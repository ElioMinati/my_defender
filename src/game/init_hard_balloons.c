/*
** EPITECH PROJECT, 2022
** init_hard_balloons
** File description:
** initalize hard balloons
*/

#include "defender.h"

void create_white_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 200;
    bloons[index].rect.width = 50;
    bloons[index].rect.top = 0;
    bloons[index].speed = 16;
    bloons[index].life = 7;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
    sfCircleShape_setFillColor(bloons[index].hitbox, sfWhite);
}

void create_purple_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 150;
    bloons[index].rect.width = 50;
    bloons[index].rect.top = 0;
    bloons[index].speed = 18;
    bloons[index].life = 8;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
    sfCircleShape_setFillColor(bloons[index].hitbox, sfWhite);
}

void create_zebra_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 100;
    bloons[index].rect.width = 50;
    bloons[index].rect.top = 0;
    bloons[index].speed = 20;
    bloons[index].life = 9;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
    sfCircleShape_setFillColor(bloons[index].hitbox, sfWhite);
}

void create_ceramic_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 50;
    bloons[index].rect.width = 50;
    bloons[index].rect.top = 0;
    bloons[index].speed = 22;
    bloons[index].life = 10;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
    sfCircleShape_setFillColor(bloons[index].hitbox, sfWhite);
}
