/*
** EPITECH PROJECT, 2022
** init_freeplay_rounds.c
** File description:
** initialise freeplay bloons
*/

#include "defender.h"

static void create_hard_bloons(int type, bloon *bloons, int i,
sfVector2f pos)
{
    if (type == 8)
        create_purple_bloon(bloons, i, pos.x, pos.y);
    if (type == 9)
        create_zebra_bloon(bloons, i, pos.x, pos.y);
    if (type == 10)
        create_ceramic_bloon(bloons, i, pos.x, pos.y);
    if (type == 11)
        create_fortified_bloon(bloons, i, pos.x, pos.y);
}

void create_bloon(int type, bloon *bloons, int i, sfVector2f pos)
{
    if (type == 0)
        create_red_bloon(bloons, i, pos.x, pos.y);
    if (type == 1)
        create_blue_bloon(bloons, i, pos.x, pos.y);
    if (type == 2)
        create_green_bloon(bloons, i, pos.x, pos.y);
    if (type == 3)
        create_blue_bloon(bloons, i, pos.x, pos.y);
    if (type == 4)
        create_yellow_bloon(bloons, i, pos.x, pos.y);
    if (type == 5)
        create_pink_bloon(bloons, i, pos.x, pos.y);
    if (type == 6)
        create_black_bloon(bloons, i, pos.x, pos.y);
    if (type == 7)
        create_white_bloon(bloons, i, pos.x, pos.y);
    create_hard_bloons(type, bloons, i, pos);
}

void init_freeplay_bloons(game *game, int round)
{
    sfVector2f pos = {-50, 330};

    init_bloons(game, 35 + round * 2);
    for (int i = 0; i < 10; ++i) {
        create_bloon((round * 6) % 12, game->bloons, i, pos);
        pos.x -= 100 - (round * 5) % 75;
    }
    for (int i = 10; i < (22 + round); ++i) {
        create_bloon((round * 7) % 12, game->bloons, i, pos);
        pos.x -= 100 - (round * 4) % 50;
    }
    for (int i = (22 + round); i < (35 + round * 2); ++i) {
        create_bloon((round * 8) % 12, game->bloons, i, pos);
        pos.x -= 100 - (round * 3) % 60;
    }
}
