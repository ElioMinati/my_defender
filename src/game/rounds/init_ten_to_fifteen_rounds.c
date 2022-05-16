/*
** EPITECH PROJECT, 2022
** init_ten_to_fifteen_rounds
** File description:
** initialise rounds 10 to 15
*/

#include "defender.h"

void init_eleven_round(game *game)
{
    int x = -50;

    init_bloons(game, 35);
    for (int i = 0; i < 10; ++i, x -= 10)
        create_red_bloon(game->bloons, i, x, 330);
    x -= 100;
    for (int i = 10; i < 20; ++i, x -= 25)
        create_blue_bloon(game->bloons, i, x, 330);
    x -= 300;
    for (int i = 20; i < 32; ++i, x -= 80)
        create_green_bloon(game->bloons, i, x, 330);
    x -= 300;
    for (int i = 32; i < 35; ++i, x -= 160)
        create_yellow_bloon(game->bloons, i, x, 330);
}

void init_twelve_round(game *game)
{
    int x = -50;

    init_bloons(game, 30);
    for (int i = 0; i < 15; ++i) {
        create_blue_bloon(game->bloons, i, x, 330);
        x -= 25;
    }
    x -= 300;
    for (int i = 15; i < 25; ++i) {
        create_green_bloon(game->bloons, i, x, 330);
        x -= 50;
    }
    x -= 300;
    for (int i = 25; i < 30; ++i) {
        create_yellow_bloon(game->bloons, i, x, 330);
        x -= 140;
    }
}

void init_thirteen_round(game *game)
{
    int x = -50;

    init_bloons(game, 73);
    for (int i = 0; i < 50; ++i) {
        create_blue_bloon(game->bloons, i, x, 330);
        x -= 25;
    }
    x -= 300;
    for (int i = 50; i < 73; ++i) {
        create_green_bloon(game->bloons, i, x, 330);
        x -= 80;
    }
}

void init_fourteen_round(game *game)
{
    int x = -50;

    init_bloons(game, 83);
    for (int i = 0; i < 49; ++i, x -= 15)
        create_red_bloon(game->bloons, i, x, 330);
    for (int i = 49; i < 64; ++i, x -= 25)
        create_blue_bloon(game->bloons, i, x, 330);
    x -= 200;
    for (int i = 64; i < 74; ++i, x -= 50)
        create_green_bloon(game->bloons, i, x, 330);
    x -= 200;
    for (int i = 74; i < 83; ++i, x -= 120)
        create_yellow_bloon(game->bloons, i, x, 330);
}

void init_fifteen_round(game *game)
{
    int x = -50;
    if (game->last_round == 0) {
        init_bloons(game, 62);
        for (int i = 0; i < 20; ++i,  x -= 15)
            create_red_bloon(game->bloons, i, x, 330);
        for (int i = 20; i < 35; ++i,  x -= 15)
            create_blue_bloon(game->bloons, i, x, 330);
        x -= 100;
        for (int i = 35; i < 47; ++i,  x -= 55)
            create_green_bloon(game->bloons, i, x, 330);
        x -= 200;
        for (int i = 47; i < 57; ++i,  x -= 75)
            create_yellow_bloon(game->bloons, i, x, 330);
        x -= 300;
        for (int i = 57; i < 62; ++i,  x -= 140)
            create_pink_bloon(game->bloons, i, x, 330);
    }
    game->last_round = 1;
}
