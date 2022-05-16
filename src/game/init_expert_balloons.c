/*
** EPITECH PROJECT, 2022
** init_expert_balloons.c
** File description:
** initialise expert balloons
*/

#include "defender.h"

void create_fortified_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 0;
    bloons[index].rect.width = 50;
    bloons[index].rect.top = 0;
    bloons[index].speed = 10;
    bloons[index].life = 11;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
    sfCircleShape_setFillColor(bloons[index].hitbox, sfWhite);
}
