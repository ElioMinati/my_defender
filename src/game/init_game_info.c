/*
** EPITECH PROJECT, 2022
** init_game_info
** File description:
** initialize different game information and sprites
*/

#include "defender.h"

void init_heart_sprite(game *game)
{
    sfVector2f pos = {20, 20};
    sfVector2f resize = {0.8, 0.8};

    game->heart_texture = sfTexture_createFromFile("src/images/heart.png",
    NULL);
    game->heart_sprite = sfSprite_create();
    sfSprite_setTexture(game->heart_sprite,
    game->heart_texture, sfFalse);
    sfSprite_setPosition(game->heart_sprite, pos);
    sfSprite_setScale(game->heart_sprite, resize);
}
