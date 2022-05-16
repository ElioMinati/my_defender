/*
** EPITECH PROJECT, 2022
** create_towers.c
** File description:
** functions used to create towers when placed
*/

#include <stdlib.h>
#include "defender.h"

void create_upgrade_buttons(buttons *button)
{
    sfVector2f pos = {1230, 643};
    sfVector2f pos1 = {1230, 800};

    button->nb_buttons = 2;
    button[0].pos = pos1;
    button[0].width = 100;
    button[0].height = 100;
    button[0].is_hover = 0;
    button[0].is_pressed = 0;
    button[0].button_type = upgrade;
    button[1].pos = pos;
    button[1].width = 100;
    button[1].height = 100;
    button[1].is_hover = 0;
    button[1].is_pressed = 0;
    button[1].button_type = radius_up;
}

void init_tower_val(tower *towers, int index)
{
    towers[index].is_shooting = 0;
    towers[index].damage = 1;
    if (towers[index].id == 4)
        towers[index].damage = 2;
    towers[index].attack = sfClock_create();
    towers[index].angle = 0;
}

void create_tesla(sfRenderWindow *win, game *game, int index)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos = {mouse.x - 37, mouse.y - 130};
    sfVector2f resize = {1.2, 1.2};

    create_rect(game, index, 74, 135);
    init_tesla(game, index, pos);
    create_inv_button(&game->towers[index].button, pos, 89, 162);
    game->towers[index].texture =
    sfTexture_createFromFile("src/images/tower1.png", NULL);
    game->towers[index].sprite = sfSprite_create();
    sfSprite_setTexture(game->towers[index].sprite,
    game->towers[index].texture, sfFalse);
    sfSprite_setTextureRect(game->towers[index].sprite,
    game->towers[index].rect);
    sfSprite_setPosition(game->towers[index].sprite, pos);
    sfSprite_setScale(game->towers[index].sprite, resize);
    game->towers[index].upgrade_buttons = malloc(2 * sizeof(buttons));
    create_upgrade_buttons(game->towers[index].upgrade_buttons);
    create_tesla_attack_sprite(game->towers, index);
    init_tower_val(game->towers, index);
}

void create_tac(sfRenderWindow *win, game *game, int index)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos = {mouse.x - 55, mouse.y - 80};

    create_rect(game, index, 108, 131);
    init_tac(game, index, pos);
    create_inv_button(&game->towers[index].button, pos, 108, 131);
    game->towers[index].texture =
    sfTexture_createFromFile("src/images/tac.png", NULL);
    game->towers[index].sprite = sfSprite_create();
    sfSprite_setTexture(game->towers[index].sprite,
    game->towers[index].texture, sfFalse);
    sfSprite_setTextureRect(game->towers[index].sprite,
    game->towers[index].rect);
    sfSprite_setPosition(game->towers[index].sprite, pos);
    game->towers[index].upgrade_buttons = malloc(2 * sizeof(buttons));
    create_upgrade_buttons(game->towers[index].upgrade_buttons);
    create_tac_attack_sprite(game->towers, index);
    init_tower_val(game->towers, index);
}
