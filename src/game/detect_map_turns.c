/*
** EPITECH PROJECT, 2022
** detect_map_turns.c
** File description:
** functions used to detect turns and set bloon pos
*/

#include "defender.h"

void detect_even_more_second_map_turns(game *game,
bloon *bloons, int index)
{
    if (bloons[index].pos.x < 1100 && bloons[index].pos.y < 80 &&
    bloons[index].pos.x > 1000)
        bloons[index].direction = down;
    if (bloons[index].pos.x < 1100 && bloons[index].pos.y > 415 &&
    bloons[index].pos.x > 1000 && bloons[index].pos.y < 460)
        bloons[index].direction = right;
    if (bloons[index].pos.x > 1650) {
        bloons[index].is_pop = 2;
        game->lives -= bloons[index].life;
        bloons[index].pos.y = -100;
    }
}

static void detect_more_fourth_map_turn(game *game, bloon *bloons,
int index)
{
    if (bloons[index].pos.x > 1000 && bloons[index].pos.y > 815 &&
    bloons[index].pos.x < 1140)
        bloons[index].direction = up;
    if (bloons[index].pos.x < 1140 && bloons[index].pos.y < 30 &&
    bloons[index].pos.x > 1000)
        bloons[index].direction = right;
    if (bloons[index].pos.x > 1315 && bloons[index].pos.y > 215 &&
    bloons[index].pos.y < 500)
        bloons[index].direction = left;
    if (bloons[index].pos.x > 740 && bloons[index].pos.y > 215 &&
    bloons[index].pos.x < 838 && bloons[index].pos.y < 500)
        bloons[index].direction = up;
    if (bloons[index].pos.y < -50 && bloons[index].pos.x > 740) {
        bloons[index].is_pop = 2;
        game->lives -= bloons[index].life;
        bloons[index].pos.y = -100;
    }
}

void detect_fourth_map_turn(game *game, bloon *bloons, int index)
{
    if (bloons[index].pos.x == 740 && bloons[index].pos.y > 200 &&
    bloons[index].pos.y < 500)
        bloons[index].direction = left;
    if (bloons[index].pos.x < 250 && bloons[index].pos.y > 200)
        bloons[index].direction = up;
    if (bloons[index].pos.x < 250 && bloons[index].pos.y < 30)
        bloons[index].direction = right;
    if (bloons[index].pos.x > 430 && bloons[index].pos.y < 30 &&
    bloons[index].pos.x < 740)
        bloons[index].direction = down;
    if (bloons[index].pos.x > 430 && bloons[index].pos.y > 815)
        bloons[index].direction = left;
    if (bloons[index].pos.x < 250 && bloons[index].pos.y < 640 &&
    bloons[index].pos.y > 500)
        bloons[index].direction = right;
    if (bloons[index].pos.x > 1315 && bloons[index].pos.y < 640)
        bloons[index].direction = down;
    detect_more_fourth_map_turn(game, bloons, index);
}
