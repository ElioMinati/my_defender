/*
** EPITECH PROJECT, 2022
** detect_turns.c
** File description:
** functions used to detect turns map specific
*/

#include "defender.h"

static void detect_more_first_map_turn(game *game, bloon *bloons, int index)
{
    if (bloons[index].pos.x > 1180 && bloons[index].pos.y < 250)
        bloons[index].direction = down;
    if (bloons[index].pos.x > 1180 && bloons[index].pos.y > 670)
        bloons[index].direction = left;
    if (bloons[index].pos.x < 700 && bloons[index].pos.y > 670 &&
    bloons[index].pos.x > 520)
        bloons[index].direction = down;
    if (bloons[index].pos.y > 1080) {
        bloons[index].is_pop = 2;
        game->lives -= bloons[index].life;
        bloons[index].pos.y = -100;
    }
}

void detect_first_map_turn(game *game, bloon *bloons, int index)
{
    if (bloons[index].pos.x > 780 && bloons[index].pos.y < 340 &&
    bloons[index].pos.x < 1000)
        bloons[index].direction = up;
    if (bloons[index].pos.x > 780 && bloons[index].pos.y < 80)
        bloons[index].direction = left;
    if (bloons[index].pos.x < 520 && bloons[index].pos.y < 80)
        bloons[index].direction = down;
    if (bloons[index].pos.x < 520 && bloons[index].pos.y > 750)
        bloons[index].direction = left;
    if (bloons[index].pos.x < 255 && bloons[index].pos.y > 750)
        bloons[index].direction = up;
    if (bloons[index].pos.x < 255 && bloons[index].pos.y < 500)
        bloons[index].direction = right;
    if (bloons[index].pos.x > 1000 && bloons[index].pos.y < 500
    && bloons[index].pos.x < 1180)
        bloons[index].direction = up;
    if (bloons[index].pos.x > 1000 && bloons[index].pos.y < 250)
        bloons[index].direction = right;
    detect_more_first_map_turn(game, bloons, index);
}

static void detect_more_second_map_turns(game *game, bloon *bloons, int index)
{
    if (bloons[index].pos.x > 1085 && bloons[index].pos.y < 530 &&
    bloons[index].pos.y > 460)
        bloons[index].direction = left;
    if (bloons[index].pos.x < 910 && bloons[index].pos.y < 530 &&
    bloons[index].pos.x > 800)
        bloons[index].direction = up;
    if (bloons[index].pos.x < 910 && bloons[index].pos.y < 290 &&
    bloons[index].pos.x > 800)
        bloons[index].direction = right;
    if (bloons[index].pos.x > 1335 && bloons[index].pos.y < 290)
        bloons[index].direction = up;
    if (bloons[index].pos.x > 1335 && bloons[index].pos.y < 80)
        bloons[index].direction = left;
    detect_even_more_second_map_turns(game, bloons, index);
}

void detect_second_map_turn(game *game, bloon *bloons, int index)
{
    if (bloons[index].pos.x == 290 && bloons[index].pos.y < 450)
        bloons[index].direction = right;
    if (bloons[index].pos.x > 580 && bloons[index].pos.y < 450 &&
    bloons[index].pos.y > 80 && bloons[index].pos.x < 700)
        bloons[index].direction = up;
    if (bloons[index].pos.x > 580 && bloons[index].pos.y < 275 &&
    bloons[index].pos.y > 80 && bloons[index].pos.x < 710)
        bloons[index].direction = left;
    if (bloons[index].pos.x < 380 && bloons[index].pos.y < 275)
        bloons[index].direction = up;
    if (bloons[index].pos.x < 380 && bloons[index].pos.y < 80)
        bloons[index].direction = right;
    if (bloons[index].pos.x > 710 && bloons[index].pos.y < 80 &&
    bloons[index].pos.x < 1000)
        bloons[index].direction = down;
    if (bloons[index].pos.x > 710 && bloons[index].pos.y > 700)
        bloons[index].direction = right;
    if (bloons[index].pos.x > 1085 && bloons[index].pos.y > 700)
        bloons[index].direction = up;
    detect_more_second_map_turns(game, bloons, index);
}
