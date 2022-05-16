/*
** EPITECH PROJECT, 2022
** init_fifteen_to_twenty_rounds.c
** File description:
** functions that initialize round 15 to 20
*/

#include "defender.h"

void init_sixteen_round(game *game)
{
    int x = -50;

    init_bloons(game, 48);
    for (int i = 0; i < 40; ++i) {
        create_green_bloon(game->bloons, i, x, 330);
        x -= 70;
    }
    x -= 100;
    for (int i = 40; i < 48; ++i) {
        create_yellow_bloon(game->bloons, i, x, 330);
        x -= 100;
    }
}

void init_seventeen_round(game *game)
{
    int x = -50;

    init_bloons(game, 20);
    for (int i = 0; i < 20; ++i) {
        create_pink_bloon(game->bloons, i, x, 330);
        x -= 75;
    }
}

void init_eighteen_round(game *game)
{
    int x = -50;

    init_bloons(game, 80);
    for (int i = 0; i < 80; ++i) {
        create_green_bloon(game->bloons, i, x, 330);
        x -= 50;
    }
}

void init_nineteen_round(game *game)
{
    int x = -50;

    init_bloons(game, 34);
    for (int i = 0; i < 10; ++i, x -= 40)
        create_green_bloon(game->bloons, i, x, 330);
    for (int i = 10; i < 14; ++i, x -= 70)
        create_yellow_bloon(game->bloons, i, x, 330);
    for (int i = 14; i < 34; ++i, x -= 80)
        create_pink_bloon(game->bloons, i, x, 330);
}

void init_twenty_round(game *game)
{
    int x = -50;

    init_bloons(game, 6);
    for (int i = 0; i < 6; ++i, x -= 75)
        create_black_bloon(game->bloons, i, x, 330);
}
