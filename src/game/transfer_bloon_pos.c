/*
** EPITECH PROJECT, 2022
** transfer_bloon_pos.c
** File description:
** functions used to transfer bloons position from map to map
*/

#include <math.h>
#include <stdlib.h>
#include "defender.h"

void transfer_bloon_pos(game *game)
{
    int temp;

    if (game->map == 2) {
        for (int i = 0; i < game->bloons->nb_bloons; ++i) {
            temp = game->bloons[i].pos.x;
            game->bloons[i].pos.x = 290;
            game->bloons[i].pos.y = abs(temp) + 1080;
            game->bloons[i].direction = up;
        }
    }
    if (game->map == 3) {
        for (int i = 0; i < game->bloons->nb_bloons; ++i) {
            temp = game->bloons[i].pos.x;
            game->bloons[i].pos.x = 740;
            game->bloons[i].pos.y = temp;
            game->bloons[i].direction = down;
        }
    }
}
