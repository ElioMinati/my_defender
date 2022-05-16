/*
** EPITECH PROJECT, 2022
** init_map.c
** File description:
** functions used to initialize the map
*/

#include <stdlib.h>
#include "my.h"
#include "defender.h"

void init_map(defender *objects)
{
    char *map_file = malloc(20 * sizeof(char));
    sfVector2f resize = {1, 1.05};

    objects->game->map = objects->map_choice;
    map_file = my_strconcat("src/images/map", my_int_to_str(
    objects->map_choice));
    map_file = my_strconcat(map_file, ".png");
    objects->game->map_texture = sfTexture_createFromFile(map_file, NULL);
    objects->game->map_sprite = sfSprite_create();
    sfSprite_setTexture(objects->game->map_sprite,
    objects->game->map_texture, sfFalse);
    sfSprite_setScale(objects->game->map_sprite, resize);
    objects->did_game = 1;
}

void init_upgrade_menu(game *game)
{
    sfVector2f pos = {1212, 128};
    sfVector2f resize = {1, 1};

    game->upgrade_texture = sfTexture_createFromFile(
    "src/images/upgrade_menu.png", NULL);
    game->upgrade_sprite = sfSprite_create();
    sfSprite_setTexture(game->upgrade_sprite,
    game->upgrade_texture, sfFalse);
    sfSprite_setPosition(game->upgrade_sprite, pos);
    sfSprite_setScale(game->upgrade_sprite, resize);
}

void init_upgrade_button(game *game)
{
    sfVector2f close_pos = {1000, 373};

    game->buttons->nb_buttons = 1;
    create_close_button(game->pause_buttons, close_pos, 1, 0);
}

void init_upgrade_gold(game *game)
{
    sfVector2f pos = {1330, 870};
    sfVector2f resize = {0.8, 0.8};
    sfVector2f pos1 = {1330, 715};

    game->first_up_gold_texture = sfTexture_createFromFile(
    "src/images/gold.png", NULL);
    game->first_up_gold_sprite = sfSprite_create();
    sfSprite_setTexture(game->first_up_gold_sprite,
    game->first_up_gold_texture, sfFalse);
    sfSprite_setPosition(game->first_up_gold_sprite, pos1);
    sfSprite_setScale(game->first_up_gold_sprite, resize);
    game->up_gold_texture = sfTexture_createFromFile(
    "src/images/gold.png", NULL);
    game->up_gold_sprite = sfSprite_create();
    sfSprite_setTexture(game->up_gold_sprite,
    game->up_gold_texture, sfFalse);
    sfSprite_setPosition(game->up_gold_sprite, pos);
    sfSprite_setScale(game->up_gold_sprite, resize);
}

void init_difficulty_params(game *game)
{
    if (game->mode == easy) {
        game->money = 85000;
        game->rounds = 15;
        game->lives = 200;
    } else if (game->mode == medium) {
        game->money = 750;
        game->rounds = 20;
        game->lives = 150;
    } else {
        game->money = 650;
        game->rounds = 25;
        game->lives = 100;
    }
}
