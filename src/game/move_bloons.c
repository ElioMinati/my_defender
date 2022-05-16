/*
** EPITECH PROJECT, 2022
** move_bloons.c
** File description:
** functions used to move bloons
*/

#include "defender.h"

static void detect_turn(game *game, bloon *bloons, int index)
{
    if (bloons->map_id == 1)
        detect_first_map_turn(game, bloons, index);
    if (bloons->map_id == 2)
        detect_second_map_turn(game, bloons, index);
    if (bloons->map_id == 3)
        detect_fourth_map_turn(game, bloons, index);
}

static void move_boss_height(bloon *bloons, int index)
{
    if (bloons[index].direction == up) {
        bloons[index].pos.y -= bloons[index].speed;
        bloons[index].boss_pos.y -= bloons[index].speed;
    }
    if (bloons[index].direction == down) {
        bloons[index].pos.y += bloons[index].speed;
        bloons[index].boss_pos.y += bloons[index].speed;
    }
}

static void move_boss(bloon *bloons, int index)
{
    sfVector2f cpos;

    if (bloons[index].direction == right) {
        bloons[index].pos.x += bloons[index].speed;
        bloons[index].boss_pos.x += bloons[index].speed;
    }
    if (bloons[index].direction == left) {
        bloons[index].pos.x -= bloons[index].speed;
        bloons[index].boss_pos.x -= bloons[index].speed;
    }
    move_boss_height(bloons, index);
    cpos.x = bloons[index].boss_pos.x - 5;
    cpos.y = bloons[index].boss_pos.y;
    sfCircleShape_setPosition(bloons[index].hitbox, cpos);
}

static void move_bloon(bloon *bloons, int index)
{
    sfVector2f cpos;

    if (bloons[index].direction == right)
        bloons[index].pos.x += bloons[index].speed;
    if (bloons[index].direction == left)
        bloons[index].pos.x -= bloons[index].speed;
    if (bloons[index].direction == up)
        bloons[index].pos.y -= bloons[index].speed;
    if (bloons[index].direction == down)
        bloons[index].pos.y += bloons[index].speed;
    cpos.x = bloons[index].pos.x - 5;
    cpos.y = bloons[index].pos.y;
    sfCircleShape_setPosition(bloons[index].hitbox, cpos);
}

void move_bloons(defender *objects)
{
    for (int i = 0; i < objects->game->bloons->nb_bloons; ++i) {
        if (objects->is_pause == 0 && objects->game->bloons[i].is_pop == 0
        && objects->game->bloons[i].is_boss == 0) {
            move_bloon(objects->game->bloons, i);
            detect_turn(objects->game, objects->game->bloons, i);
        }
        if (objects->is_pause == 0 && objects->game->bloons[i].is_pop == 0
        && objects->game->bloons[i].is_boss >= 1) {
            move_boss(objects->game->bloons, i);
            detect_turn(objects->game, objects->game->bloons, i);
        }
    }
}
