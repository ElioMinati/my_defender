/*
** EPITECH PROJECT, 2022
** init_twenty_to_twenty_five_rounds
** File description:
** initialize rounds 20 to 25
*/

#include "defender.h"

void init_twenty_o_round(game *game)
{
    int x = -50;

    init_bloons(game, 54);
    for (int i = 0; i < 40; ++i, x -= 75)
        create_yellow_bloon(game->bloons, i, x, 330);
    x -= 400;
    for (int i = 40; i < 54; ++i, x -= 100)
        create_pink_bloon(game->bloons, i, x, 330);
}

void init_twenty_to_round(game *game)
{
    int x = -50;

    init_bloons(game, 16);
    for (int i = 0; i < 16; ++i, x -= 125)
        create_white_bloon(game->bloons, i, x, 330);
}

void init_twenty_te_round(game *game)
{
    int x = -50;

    init_bloons(game, 14);
    for (int i = 0; i < 7; ++i, x -= 100)
        create_white_bloon(game->bloons, i, x, 330);
    for (int i = 7; i < 14; ++i, x -= 80)
        create_black_bloon(game->bloons, i, x, 330);
}

void init_twenty_fr_round(game *game)
{
    int x = -50;

    init_bloons(game, 40);
    for (int i = 0; i < 20; ++i, x -= 50)
        create_pink_bloon(game->bloons, i, x, 330);
    for (int i = 20; i < 40; ++i, x -= 15)
        create_blue_bloon(game->bloons, i, x, 330);
}

void init_twenty_fv_round(game *game)
{
    int x = -50;

    init_bloons(game, 35);
    for (int i = 0; i < 25; ++i, x -= 50)
        create_yellow_bloon(game->bloons, i, x, 330);
    for (int i = 25; i < 35; ++i, x -= 150)
        create_purple_bloon(game->bloons, i, x, 330);
}
