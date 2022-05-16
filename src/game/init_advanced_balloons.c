/*
** EPITECH PROJECT, 2022
** init_advanced_ballons.c
** File description:
** initialise advanced ballons
*/

#include "defender.h"

void create_green_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 400;
    bloons[index].rect.width = 50;
    bloons[index].rect.top = 0;
    bloons[index].speed = 8;
    bloons[index].life = 3;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
}

void create_yellow_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 350;
    bloons[index].rect.width = 48;
    bloons[index].rect.top = 0;
    bloons[index].speed = 10;
    bloons[index].life = 4;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
}

void create_pink_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 300;
    bloons[index].rect.width = 50;
    bloons[index].rect.top = 0;
    bloons[index].speed = 12;
    bloons[index].life = 5;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
    sfCircleShape_setFillColor(bloons[index].hitbox, sfWhite);
}

void create_black_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 250;
    bloons[index].rect.width = 50;
    bloons[index].rect.top = 0;
    bloons[index].speed = 14;
    bloons[index].life = 6;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
    sfCircleShape_setFillColor(bloons[index].hitbox, sfWhite);
}
