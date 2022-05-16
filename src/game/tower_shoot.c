/*
** EPITECH PROJECT, 2022
** tower_shoot.c
** File description:
** functions handling tower shooting
*/

#include <math.h>
#include "my.h"
#include "defender.h"

int is_in_tower_radius(bloon bloon, tower tower)
{
    sfVector2f b_pos = sfCircleShape_getPosition(bloon.hitbox);
    sfVector2f t_pos = {tower.button.pos.x + tower.offset.x - tower.rad,
    tower.button.pos.y + tower.offset.y - tower.rad};
    float rad = sfCircleShape_getRadius(bloon.hitbox);
    float res = my_compute_power_rec((b_pos.x + rad) -
    (t_pos.x + tower.rad), 2);

    res += my_compute_power_rec((b_pos.y + rad) - (t_pos.y + tower.rad) , 2);
    if (res <= my_compute_power_rec((rad + tower.rad), 2))
        return 1;
    return 0;
}

static void tac_shoot(bloon *bloons, defender *objects, int i)
{
    int did_shoot = 0;
    float time = sfTime_asSeconds(sfClock_getElapsedTime(
    objects->game->towers[i].cooldown));

    for (int j = 0; j < bloons->nb_bloons; ++j) {
        if (is_in_tower_radius(bloons[j], objects->game->towers[i]) == 1 &&
        time > objects->game->towers[i].cool_time && bloons[j].is_pop == 0) {
            do_shoot(objects, bloons, i, j);
            did_shoot = 1;
        }
    }
    handle_tac_shooting(objects, i, did_shoot);
}

void set_shoot_angle(bloon bloon, tower *towers, int i, int id)
{
    sfVector2f zap_vector = {255, 441};
    sfVector2f sauda_vector = {0, 100};
    sfVector2f sniper_vector = {-100, 0};

    if (id == 1)
        init_shoot_angle(bloon, towers, i, zap_vector);
    if (id == 3)
        init_shoot_angle(bloon, towers, i, sauda_vector);
    if (id == 4)
        init_shoot_angle(bloon, towers, i, sniper_vector);
}

static void handle_shoot(bloon *bloons, defender *objects, int j, int i)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(
    objects->game->towers[i].cooldown));

    if (is_in_tower_radius(bloons[j], objects->game->towers[i]) == 1 &&
    time > objects->game->towers[i].cool_time && bloons[j].is_pop == 0
    && objects->game->towers[i].id != 4) {
        set_shoot_angle(bloons[j], objects->game->towers, i,
        objects->game->towers[i].id);
        sfClock_restart(objects->game->towers[i].attack);
        sfClock_restart(objects->game->towers[i].cooldown);
        do_shoot(objects, bloons, i, j);
    }
    detect_sniper_shot(bloons, objects, j, i);
    shoot(objects->window, objects->game->towers[i]);
}

void tower_shoot_handling(defender *objects, bloon *bloons)
{
    if (objects->game->towers == NULL)
        return;
    for (int i = 0; i < objects->game->towers->nb_towers; ++i) {
        if (objects->game->towers[i].id == 2) {
            tac_shoot(bloons, objects, i);
            continue;
        }
        for (int j = 0; j < bloons->nb_bloons; ++j) {
            handle_shoot(bloons, objects, j, i);
        }
    }
}
