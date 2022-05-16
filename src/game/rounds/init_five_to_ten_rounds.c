/*
** EPITECH PROJECT, 2022
** init_five_to_ten_rounds
** File description:
** initialise rounds 5 to 10
*/

#include "defender.h"

void init_six_round(game *game)
{
    int x = -50;

    init_bloons(game, 34);
    for (int i = 0; i < 15; ++i) {
        create_red_bloon(game->bloons, i, x, 330);
        x -= 25;
    }
    x -= 500;
    for (int i = 15; i < 30; ++i) {
        create_blue_bloon(game->bloons, i, x, 330);
        x -= 100;
    }
    x -= 400;
    for (int i = 30; i < 34; ++i) {
        create_green_bloon(game->bloons, i, x, 330);
        x -= 150;
    }
}

void init_seven_round(game *game)
{
    int x = -50;

    init_bloons(game, 45);
    for (int i = 0; i < 20; ++i) {
        create_red_bloon(game->bloons, i, x, 330);
        x -= 25;
    }
    for (int i = 20; i < 40; ++i) {
        create_blue_bloon(game->bloons, i, x, 330);
        x -= 70;
    }
    x -= 500;
    for (int i = 40; i < 45; ++i) {
        create_green_bloon(game->bloons, i, x, 330);
        x -= 100;
    }
}

void init_eight_round(game *game)
{
    int x = -50;

    init_bloons(game, 44);
    for (int i = 0; i < 10; ++i) {
        create_red_bloon(game->bloons, i, x, 330);
        x -= 25;
    }
    x -= 300;
    for (int i = 10; i < 30; ++i) {
        create_blue_bloon(game->bloons, i, x, 330);
        x -= 50;
    }
    x -= 400;
    for (int i = 30; i < 44; ++i) {
        create_green_bloon(game->bloons, i, x, 330);
        x -= 90;
    }
}

void init_nine_round(game *game)
{
    int x = -50;

    init_bloons(game, 30);
    for (int i = 0; i < 30; ++i) {
        create_green_bloon(game->bloons, i, x, 330);
        x -= 90;
    }
}

void init_ten_round(game *game)
{
    int x = -50;

    init_bloons(game, 102);
    for (int i = 0; i < 102; ++i) {
        create_blue_bloon(game->bloons, i, x, 330);
        x -= 25;
    }
}
