/*
** EPITECH PROJECT, 2022
** display_bloons.c
** File description:
** functions used to display bloons
*/

#include "defender.h"

void display_death_anim(sfRenderWindow *win, bloon *bloons,
sfClock *clock, int i)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    sfIntRect rect;

    rect.left = 550;
    rect.width = 56;
    rect.top = 0;
    rect.height = 65;
    sfSprite_setTextureRect(bloons->sprite, rect);
    sfSprite_setPosition(bloons->sprite, bloons[i].pos);
    sfRenderWindow_drawSprite(win, bloons->sprite, NULL);
    if (time > 0.1)
        bloons[i].is_pop = 2;
}

static void display_moabs(defender *objects, int i)
{
    if (objects->game->bloons[i].is_pop == 0 &&
    objects->game->bloons[i].is_boss == 2) {
        sfSprite_setPosition(objects->game->bloons->blue_moab_sprite,
        objects->game->bloons[i].boss_pos);
        sfRenderWindow_drawSprite(objects->window,
        objects->game->bloons->blue_moab_sprite, NULL);
    }
    if (objects->game->bloons[i].is_pop == 0 &&
    objects->game->bloons[i].is_boss == 3) {
        sfSprite_setPosition(objects->game->bloons->red_moab_sprite,
        objects->game->bloons[i].boss_pos);
        sfRenderWindow_drawSprite(objects->window,
        objects->game->bloons->red_moab_sprite, NULL);
    }
}

void display_bloon(defender *objects, int i)
{
    if (objects->game->bloons[i].is_pop == 0 &&
    objects->game->bloons[i].is_boss == 0) {
        sfSprite_setPosition(objects->game->bloons->sprite,
        objects->game->bloons[i].pos);
        sfSprite_setTextureRect(objects->game->bloons->sprite,
        objects->game->bloons[i].rect);
        sfRenderWindow_drawSprite(objects->window,
        objects->game->bloons->sprite, NULL);
    } else if (objects->game->bloons[i].is_pop == 1 &&
    objects->game->bloons[i].is_boss == 0)
        display_death_anim(objects->window, objects->game->bloons,
        objects->game->bloons[i].death_clock, i);
    if (objects->game->bloons[i].is_pop == 0 &&
    objects->game->bloons[i].is_boss == 1) {
        sfSprite_setPosition(objects->game->bloons->gb_sprite,
        objects->game->bloons[i].boss_pos);
        sfRenderWindow_drawSprite(objects->window,
        objects->game->bloons->gb_sprite, NULL);
    }
    display_moabs(objects, i);
}

static void display_all_bloons(defender *objects)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(objects->clock));

    for (int i = 0; i < objects->game->bloons->nb_bloons; ++i)
        display_bloon(objects, i);
    if (time < 0.02)
        return;
    if (objects->is_pause == 0) {
        sfClock_restart(objects->clock);
        move_bloons(objects);
        if (objects->game->towers == NULL)
            return;
        tower_shoot_handling(objects, objects->game->bloons);
    }
    if (objects->game->towers == NULL)
        return;
    for (int i = 0; i < objects->game->towers->nb_towers; ++i) {
        if (objects->game->towers[i].id == 3)
            handle_sauda_shooting(objects, i);
    }
}

void display_bloons(defender *objects)
{
    if (objects->game->current_round >= 1)
        display_all_bloons(objects);
}
