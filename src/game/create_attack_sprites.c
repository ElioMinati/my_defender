/*
** EPITECH PROJECT, 2022
** create_attack_sprites
** File description:
** functions used to create attack sprites
*/

#include "defender.h"

void create_tesla_attack_sprite(tower *towers, int i)
{
    sfVector2f resize = {0.5, 0.5};

    towers[i].attack_texture = sfTexture_createFromFile("src/images/zap.png",
    NULL);
    towers[i].attack_sprite = sfSprite_create();
    sfSprite_setTexture(towers[i].attack_sprite, towers[i].attack_texture,
    sfFalse);
    sfSprite_setScale(towers[i].attack_sprite, resize);
}

void create_sniper_attack_sprite(tower *towers, int i)
{
    sfVector2f resize = {1, 1};

    towers[i].attack_texture = sfTexture_createFromFile(
    "src/images/fire.png", NULL);
    towers[i].attack_sprite = sfSprite_create();
    sfSprite_setTexture(towers[i].attack_sprite, towers[i].attack_texture,
    sfFalse);
    sfSprite_setScale(towers[i].attack_sprite, resize);
}

void create_tac_attack_sprite(tower *towers, int i)
{
    sfVector2f resize = {1, 1};
    sfIntRect rect;
    sfVector2f pos = {towers[i].pos.x - 68,
    towers[i].pos.y - 33};

    rect.left = 0;
    rect.top = 0;
    rect.width = 235;
    rect.height = 229;
    towers[i].attack_texture = sfTexture_createFromFile(
    "src/images/nail_spritesheet.png", NULL);
    towers[i].attack_sprite = sfSprite_create();
    towers[i].attack_rect = rect;
    sfSprite_setTexture(towers[i].attack_sprite, towers[i].attack_texture,
    sfFalse);
    sfSprite_setTextureRect(towers[i].attack_sprite, rect);
    sfSprite_setPosition(towers[i].attack_sprite, pos);
    sfSprite_setScale(towers[i].attack_sprite, resize);
}
