/*
** EPITECH PROJECT, 2022
** shoot.c
** File description:
** functions used to SHOOT
*/

#include <math.h>
#include <stdlib.h>
#include "defender.h"

void do_shoot(defender *objects, bloon *bloons, int i, int j)
{
    if (bloons[j].life >= 1 && bloons[j].is_boss == 0) {
        if (bloons[j].rect.left == 0)
            bloons[j].speed = 24;
        bloons[j].rect.left += 50 * objects->game->towers[i].damage;
        bloons[j].speed -= 2 * objects->game->towers[i].damage;
        bloons[j].life -= objects->game->towers[i].damage;
    }
    if (bloons[j].life >= 1 && bloons[j].is_boss >= 1)
        bloons[j].life -= objects->game->towers[i].damage;
    if (bloons[j].life < 1) {
        bloons[j].death_clock = sfClock_create();
        bloons[j].is_pop = 1;
    }
    objects->game->money += objects->game->towers[i].damage + bloons[j].life;
}

void shoot(sfRenderWindow *win, tower tower)
{
    sfVector2f pos = {tower.pos.x + tower.offset.x, tower.pos.y + 15};
    float time = sfTime_asSeconds(sfClock_getElapsedTime(tower.attack));

    if (time < 0.1 && tower.id == 1) {
        sfSprite_setPosition(tower.attack_sprite, pos);
        sfSprite_setRotation(tower.attack_sprite, tower.angle);
        sfRenderWindow_drawSprite(win, tower.attack_sprite, NULL);
    }
    if (time < 0.1 && tower.id == 3) {
        sfSprite_setRotation(tower.sprite, tower.angle);
    }
    if (time < 0.1 && tower.id == 4) {
        sfSprite_setRotation(tower.sprite, tower.angle);
    }
}

void detect_sniper_shot(bloon *bloons, defender *objects, int j, int i)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(
    objects->game->towers[i].cooldown));

    if (objects->game->towers[i].id == 4 && time >
    objects->game->towers[i].cool_time && bloons[j].is_pop == 0 &&
    bloons[j].pos.x > 0 && bloons[j].pos.y > 0 && bloons[j].pos.y < 980
    && bloons[j].pos.x < 1800) {
        set_shoot_angle(bloons[j], objects->game->towers, i,
        objects->game->towers[i].id);
        sfClock_restart(objects->game->towers[i].attack);
        sfClock_restart(objects->game->towers[i].cooldown);
        do_shoot(objects, bloons, i, j);
    }
    if (objects->game->towers[i].id == 4 &&
    sfTime_asSeconds(sfClock_getElapsedTime(
    objects->game->towers[i].attack)) < 0.05)
        sniper_shoot_anim(objects, objects->game->towers[i]);
}
