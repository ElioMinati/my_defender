/*
** EPITECH PROJECT, 2022
** place_tower.c
** File description:
** functions used to place a tower
*/

#include <stdlib.h>
#include "defender.h"

static int verify_tower_placing_second(defender *objects)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(objects->window);

    if (mouse.x > 1565 || mouse.y < 100)
        return 1;
    if (mouse.x > 240 && mouse.x < 390 && mouse.y > 450)
        return 1;
    if (mouse.x > 390 && mouse.x < 660 && mouse.y > 450 && mouse.y < 600)
        return 1;
    if (mouse.x > 390 && mouse.x < 650 && mouse.y > 450 && mouse.y < 730)
        return 1;
    if (mouse.x > 550 && mouse.x < 660 && mouse.y > 250 && mouse.y < 450)
        return 1;
    if (mouse.x > 320 && mouse.x < 660 && mouse.y > 250 && mouse.y < 380)
        return 1;
    return verify_tower_placing_secondm(mouse);
}

int is_touching_illegal_item(defender *objects)
{
    if (objects->game->map == 1)
        return verify_tower_placing_first(objects);
    if (objects->game->map == 2)
        return verify_tower_placing_second(objects);
    return 0;
}

static void transfer_tower(game *game, tower *towers, int i)
{
    towers[i].pos = game->towers[i].pos;
    towers[i].rect = game->towers[i].rect;
    towers[i].resize = game->towers[i].resize;
    towers[i].id = game->towers[i].id;
    towers[i].texture = game->towers[i].texture;
    towers[i].sprite = game->towers[i].sprite;
    towers[i].button = game->towers[i].button;
    towers[i].level = game->towers[i].level;
    towers[i].offset = game->towers[i].offset;
    towers[i].rad = game->towers[i].rad;
    towers[i].rad_level = game->towers[i].rad_level;
    towers[i].radius_up_prices = game->towers[i].radius_up_prices;
    towers[i].upgrade_buttons = game->towers[i].upgrade_buttons;
    towers[i].upgrade_prices = game->towers[i].upgrade_prices;
    towers[i].cooldown = game->towers[i].cooldown;
    towers[i].cool_time = game->towers[i].cool_time;
    towers[i].angle = game->towers[i].angle;
    towers[i].attack_texture = game->towers[i].attack_texture;
    towers[i].attack_sprite = game->towers[i].attack_sprite;
    towers[i].attack = game->towers[i].attack;
}

void alloc_towers(game *game)
{
    tower *towers = malloc((game->towers->nb_towers + 1) * sizeof(tower));

    towers->nb_towers = game->towers->nb_towers + 1;
    for (int i = 0; i < game->towers->nb_towers; ++i) {
        transfer_tower(game, towers, i);
        towers[i].attack_rect = game->towers[i].attack_rect;
        towers[i].is_shooting = game->towers[i].is_shooting;
        towers[i].damage = game->towers[i].damage;
    }
    free(game->towers);
    game->towers = towers;
}

void place_tower(defender *objects)
{
    int index;

    if (objects->game->towers == NULL) {
        objects->game->towers = malloc(1 * sizeof(tower));
        objects->game->towers->nb_towers = 1;
    } else
        alloc_towers(objects->game);
    index = objects->game->towers->nb_towers - 1;
    if (objects->game->card_id == 1)
        create_tesla(objects->window, objects->game, index);
    if (objects->game->card_id == 2)
        create_tac(objects->window, objects->game, index);
    if (objects->game->card_id == 3)
        create_sauda(objects->window, objects->game, index);
    if (objects->game->card_id == 4)
        create_sniper(objects->window, objects->game, index);
    objects->game->money -= objects->game->towers[index].price;
}
