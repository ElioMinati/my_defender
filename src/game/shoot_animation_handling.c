/*
** EPITECH PROJECT, 2022
** handle_shoot_anims
** File description:
** functions used to handle shooting animations of towers
*/

#include "defender.h"

void handle_tac_shooting(defender *objects, int i, int did_shoot)
{
    if (did_shoot == 1) {
        objects->game->towers[i].attack_rect.left = 0;
        objects->game->towers[i].attack_rect.width = 235;
        sfClock_restart(objects->game->towers[i].attack);
        sfClock_restart(objects->game->towers[i].cooldown);
    }
    move_tac_rect(objects->window, objects->game->towers, i);
}

void handle_sauda_shooting(defender *objects, int i)
{
    move_sauda_rect(objects->game->towers, i);
}

void sniper_shoot_anim(defender *objects, tower tower)
{
    sfVector2f pos = {tower.pos.x + tower.offset.x,
    tower.pos.y + tower.offset.y};
    sfVector2f o_pos = {134, 20};

    sfSprite_setOrigin(tower.attack_sprite, o_pos);
    sfSprite_setPosition(tower.attack_sprite, pos);
    sfSprite_setRotation(tower.attack_sprite, tower.angle);
    sfRenderWindow_drawSprite(objects->window, tower.attack_sprite, NULL);
}
