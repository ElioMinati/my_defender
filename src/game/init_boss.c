/*
** EPITECH PROJECT, 2022
** init_boss.c
** File description:
** initialise bloon bosses
*/

#include "defender.h"

void init_giant_balloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};
    sfVector2f boss_pos = {x - 100, y - 100};

    if (bloons->map_id == 1)
        bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].boss_pos = boss_pos;
    bloons[index].speed = 9;
    bloons[index].life = 25;
    bloons[index].nb_moves = 1;
    bloons[index].is_boss = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, boss_pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 100);
}

void init_blue_moab(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    if (bloons->map_id == 1)
        bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].speed = 7;
    bloons[index].life = 50;
    bloons[index].nb_moves = 1;
    bloons[index].is_boss = 2;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 100);
}

void init_red_moab(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    if (bloons->map_id == 1)
        bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].speed = 5;
    bloons[index].life = 100;
    bloons[index].nb_moves = 1;
    bloons[index].is_boss = 3;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 100);
}