/*
** EPITECH PROJECT, 2022
** create_case.c
** File description:
** functions used to create map case
*/

#include "defender.h"

void create_case(map_case *map_case, int i, sfVector2f pos, char *map)
{
    sfVector2f resize = {0.21, 0.23};

    map_case[i].pos = pos;
    map_case[i].is_hover = 1;
    map_case[i].is_pressed = 1;
    map_case[i].texture = sfTexture_createFromFile("src/images/map_case.png",
    NULL);
    map_case[i].sprite = sfSprite_create();
    sfSprite_setPosition(map_case[i].sprite, map_case[i].pos);
    sfSprite_setTexture(map_case[i].sprite, map_case[i].texture,
    sfFalse);
    map_case[i].map_texture = sfTexture_createFromFile(map,
    NULL);
    map_case[i].map_sprite = sfSprite_create();
    pos.x += 12;
    pos.y += 12;
    sfSprite_setPosition(map_case[i].map_sprite, pos);
    sfSprite_setTexture(map_case[i].map_sprite, map_case[i].map_texture,
    sfFalse);
    sfSprite_setScale(map_case[i].map_sprite, resize);
}
