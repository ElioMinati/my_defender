/*
** EPITECH PROJECT, 2022
** create_advanced_towers.c
** File description:
** create advanced towers
*/

#include <stdlib.h>
#include "defender.h"

void create_sauda(sfRenderWindow *win, game *game, int index)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos = {mouse.x - 125, mouse.y - 90};
    sfVector2f fmouse = {mouse.x, mouse.y};
    sfVector2f pos1 = {mouse.x - 50, mouse.y - 90};

    create_rect(game, index, 250, 179);
    init_sauda(game, index, pos);
    create_inv_button(&game->towers[index].button, pos1, 100, 179);
    game->towers[index].texture =
    sfTexture_createFromFile("src/images/sauda_spritesheet.png", NULL);
    game->towers[index].sprite = sfSprite_create();
    sfSprite_setTexture(game->towers[index].sprite,
    game->towers[index].texture, sfFalse);
    sfSprite_setTextureRect(game->towers[index].sprite,
    game->towers[index].rect);
    sfSprite_setOrigin(game->towers[index].sprite, game->towers[index].offset);
    game->towers[index].upgrade_buttons = malloc(2 * sizeof(buttons));
    sfSprite_setPosition(game->towers[index].sprite, fmouse);
    create_upgrade_buttons(game->towers[index].upgrade_buttons);
    init_tower_val(game->towers, index);
}

void create_sniper(sfRenderWindow *win, game *game, int index)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos = {mouse.x - 90, mouse.y - 68};
    sfVector2f fmouse = {mouse.x, mouse.y};

    create_rect(game, index, 140, 136);
    init_sniper(game, index, pos);
    create_inv_button(&game->towers[index].button, pos, 140, 136);
    game->towers[index].texture =
    sfTexture_createFromFile("src/images/sniper_spritesheet.png", NULL);
    game->towers[index].sprite = sfSprite_create();
    sfSprite_setTexture(game->towers[index].sprite,
    game->towers[index].texture, sfFalse);
    sfSprite_setTextureRect(game->towers[index].sprite,
    game->towers[index].rect);
    sfSprite_setOrigin(game->towers[index].sprite, game->towers[index].offset);
    game->towers[index].upgrade_buttons = malloc(2 * sizeof(buttons));
    sfSprite_setPosition(game->towers[index].sprite, fmouse);
    create_upgrade_buttons(game->towers[index].upgrade_buttons);
    init_tower_val(game->towers, index);
    create_sniper_attack_sprite(game->towers, index);
}
