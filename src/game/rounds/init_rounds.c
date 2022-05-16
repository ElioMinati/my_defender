/*
** EPITECH PROJECT, 2022
** init_rounds
** File description:
** functions used to initalize rounds
*/

#include "defender.h"

void init_first_round(game *game)
{
    int x = -50;

    init_bloons(game, 20);
    for (int i = 0; i < 20; ++i) {
        create_red_bloon(game->bloons, i, x, 330);
        x -= 150;
    }
}

void init_second_round(game *game)
{
    int x = -50;

    init_bloons(game, 35);
    for (int i = 0; i < 35; ++i) {
        create_red_bloon(game->bloons, i, x, 330);
        x -= 100;
    }
}

void init_third_round(game *game)
{
    int x = -50;

    init_bloons(game, 30);
    for (int i = 0; i < 25; ++i) {
        create_red_bloon(game->bloons, i, x, 330);
        x -= 100;
    }
    x -= 300;
    for (int i = 25; i < 30; ++i) {
        create_blue_bloon(game->bloons, i, x, 330);
        x -= 100;
    }
}

void init_fourth_round(game *game)
{
    int x = -50;

    init_bloons(game, 53);
    for (int i = 0; i < 35; ++i) {
        create_red_bloon(game->bloons, i, x, 330);
        x -= 50;
    }
    x -= 300;
    for (int i = 35; i < 53; ++i) {
        create_blue_bloon(game->bloons, i, x, 330);
        x -= 100;
    }
}

void init_fifth_round(game *game)
{
    int x = -50;

    init_bloons(game, 33);
    for (int i = 0; i < 5; ++i) {
        create_red_bloon(game->bloons, i, x, 330);
        x -= 50;
    }
    x -= 300;
    for (int i = 5; i < 33; ++i) {
        create_blue_bloon(game->bloons, i, x, 330);
        x -= 80;
    }
}
