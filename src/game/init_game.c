/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** initialize the GAME
*/

#include <stdlib.h>
#include "my.h"
#include "defender.h"

static void init_sidebar(game *game)
{
    sfVector2f pos = {1605, 0};
    sfVector2f resize = {1.2, 1};

    game->sidebar_texture = sfTexture_createFromFile("src/images/sidebar.png",
    NULL);
    game->sidebar_sprite = sfSprite_create();
    sfSprite_setTexture(game->sidebar_sprite,
    game->sidebar_texture, sfFalse);
    sfSprite_setPosition(game->sidebar_sprite, pos);
    sfSprite_setScale(game->sidebar_sprite, resize);
}

static void init_pause_menu(game *game)
{
    sfVector2f pos = {330, 370};
    sfVector2f resize = {0.9, 0.9};

    game->pause_texture = sfTexture_createFromFile("src/images/pause.png",
    NULL);
    game->pause_sprite = sfSprite_create();
    sfSprite_setTexture(game->pause_sprite,
    game->pause_texture, sfFalse);
    sfSprite_setPosition(game->pause_sprite, pos);
    sfSprite_setScale(game->pause_sprite, resize);
}

static void init_game_buttons(game *game)
{
    sfVector2f settings_pos = {1520, 20};
    sfVector2f close_pos = {350, 373};
    sfVector2f home_pos = {710, 450};
    sfVector2f close2_pos = {1540, 135};
    sfVector2f play_pos = {1500, 920};
    sfVector2f exit_pos = {20, 930};

    game->buttons->nb_buttons = 2;
    game->pause_buttons->nb_buttons = 3;
    game->upgrade_buttons->nb_buttons = 1;
    create_settings_button(game->buttons, settings_pos, 1, 0);
    create_play_round_button(game->buttons, play_pos, 0.8, 1);
    create_close_button(game->pause_buttons, close_pos, 1, 0);
    create_home_button(game->pause_buttons, home_pos, 1, 1);
    create_exit_button(game->pause_buttons, exit_pos, 1, 2);
    create_close_button(game->upgrade_buttons, close2_pos, 1, 0);
}

static void init_money_rounds(game *game)
{
    sfVector2f pos = {170, 20};
    sfVector2f resize = {0.8, 0.8};

    init_difficulty_params(game);
    game->gold_texture = sfTexture_createFromFile("src/images/gold.png",
    NULL);
    game->gold_sprite = sfSprite_create();
    sfSprite_setTexture(game->gold_sprite,
    game->gold_texture, sfFalse);
    sfSprite_setPosition(game->gold_sprite, pos);
    sfSprite_setScale(game->gold_sprite, resize);
    game->current_round = 0;
    game->last_round = 0;
}

void init_game(defender *objects)
{
    objects->game->buttons = malloc(2 * sizeof(buttons));
    objects->game->pause_buttons = malloc(3 * sizeof(buttons));
    objects->game->cards = malloc(4 * sizeof(buttons));
    objects->game->upgrade_buttons = malloc(1 * sizeof(buttons));
    objects->game->towers = NULL;
    objects->game->card_id = -1;
    objects->game->bloons = NULL;
    objects->is_upgrade = 0;
    objects->game->is_infinite = 0;
    init_map(objects);
    init_sidebar(objects->game);
    init_game_buttons(objects->game);
    init_pause_menu(objects->game);
    init_upgrade_menu(objects->game);
    init_money_rounds(objects->game);
    init_cards(objects->game->cards);
    init_upgrade_gold(objects->game);
    init_heart_sprite(objects->game);
    init_end_menu(objects->game);
    init_effects(objects->game);
}
