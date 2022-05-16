/*
** EPITECH PROJECT, 2022
** init_balloons
** File description:
** functions used to init different types of ballons
*/

#include <stdlib.h>
#include "defender.h"

void init_bloon_sprites(game *game)
{
    game->bloons->texture = sfTexture_createFromFile("src/images/bloons.png",
    NULL);
    game->bloons->sprite = sfSprite_create();
    game->bloons->gb_texture = sfTexture_createFromFile(
    "src/images/cr_balloon.png", NULL);
    game->bloons->gb_sprite = sfSprite_create();
    game->bloons->blue_moab_texture = sfTexture_createFromFile(
    "src/images/moab.png", NULL);
    game->bloons->blue_moab_sprite = sfSprite_create();
    game->bloons->red_moab_texture = sfTexture_createFromFile(
    "src/images/red_moab.png", NULL);
    game->bloons->red_moab_sprite = sfSprite_create();
    sfSprite_setTexture(game->bloons->sprite,
    game->bloons->texture, sfFalse);
    sfSprite_setTexture(game->bloons->gb_sprite,
    game->bloons->gb_texture, sfFalse);
    sfSprite_setTexture(game->bloons->blue_moab_sprite,
    game->bloons->blue_moab_texture, sfFalse);
    sfSprite_setTexture(game->bloons->red_moab_sprite,
    game->bloons->red_moab_texture, sfFalse);
}

void init_bloons(game *game, int size)
{
    sfVector2f resize = {0.5, 0.5};

    game->bloons = malloc(size * sizeof(bloon));
    init_bloon_sprites(game);
    sfSprite_setScale(game->bloons->gb_sprite, resize);
    game->bloons->nb_bloons = size;
    game->bloons->map_id = game->map;
}

void create_red_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 500;
    bloons[index].rect.width = 50;
    bloons[index].rect.top = 0;
    bloons[index].speed = 6;
    bloons[index].life = 1;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
}

void create_blue_bloon(bloon *bloons, int index, int x, int y)
{
    sfVector2f pos = {x, y};

    bloons[index].direction = right;
    bloons[index].is_pop = 0;
    bloons[index].pos = pos;
    bloons[index].rect.height = 65;
    bloons[index].rect.left = 450;
    bloons[index].rect.width = 50;
    bloons[index].rect.top = 0;
    bloons[index].speed = 8;
    bloons[index].life = 2;
    bloons[index].is_boss = 0;
    bloons[index].nb_moves = 1;
    bloons[index].hitbox = sfCircleShape_create();
    sfCircleShape_setPosition(bloons[index].hitbox, pos);
    sfCircleShape_setRadius(bloons[index].hitbox, 30);
}
