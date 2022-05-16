/*
** EPITECH PROJECT, 2022
** create_tower_rects
** File description:
** create tower rectangles
*/

#include "defender.h"

void create_rect(game *game, int index, int width, int height)
{
    game->towers[index].rect.width = width;
    game->towers[index].rect.top = 0;
    game->towers[index].rect.left = 0;
    game->towers[index].rect.height = height;
}

void move_even_more_tac_rect(float time, sfRenderWindow *win,
tower *towers, int i)
{
    if (time < 0.20) {
        towers[i].attack_rect.left = 900;
        towers[i].attack_rect.width = 242;
        sfSprite_setTextureRect(towers[i].attack_sprite,
        towers[i].attack_rect);
        sfRenderWindow_drawSprite(win, towers[i].attack_sprite, NULL);
        return;
    }
}

void move_more_tac_rect(float time, sfRenderWindow *win,
tower *towers, int i)
{
    if (time < 0.12) {
        towers[i].attack_rect.left = 450;
        towers[i].attack_rect.width = 228;
        sfSprite_setTextureRect(towers[i].attack_sprite,
        towers[i].attack_rect);
        sfRenderWindow_drawSprite(win, towers[i].attack_sprite, NULL);
        return;
    }
    if (time < 0.16) {
        towers[i].attack_rect.left = 673;
        towers[i].attack_rect.width = 224;
        sfSprite_setTextureRect(towers[i].attack_sprite,
        towers[i].attack_rect);
        sfRenderWindow_drawSprite(win, towers[i].attack_sprite, NULL);
        return;
    }
    move_even_more_tac_rect(time, win, towers, i);
}

void move_tac_rect(sfRenderWindow *win, tower *towers, int i)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(
    towers[i].attack));

    if (time < 0.04) {
        sfSprite_setTextureRect(towers[i].attack_sprite,
        towers[i].attack_rect);
        sfRenderWindow_drawSprite(win, towers[i].attack_sprite, NULL);
        return;
    }
    if (time < 0.08) {
        towers[i].attack_rect.left = 224;
        towers[i].attack_rect.width = 226;
        towers[i].attack_rect.top = 5;
        sfSprite_setTextureRect(towers[i].attack_sprite,
        towers[i].attack_rect);
        sfRenderWindow_drawSprite(win, towers[i].attack_sprite, NULL);
        return;
    }
    move_more_tac_rect(time, win, towers, i);
}

void move_sauda_rect(tower *towers, int i)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(
    towers[i].attack));

    if (time > 0.08 && time < 0.16) {
        towers[i].rect.left = 250;
        sfSprite_setTextureRect(towers[i].sprite, towers[i].rect);
    }
    if (time > 0.16 && time < 0.24) {
        towers[i].rect.left = 500;
        sfSprite_setTextureRect(towers[i].sprite, towers[i].rect);
    }
    if (time > 0.24 && time < 0.32) {
        towers[i].rect.left = 750;
        sfSprite_setTextureRect(towers[i].sprite, towers[i].rect);
    }
    if (time > 0.32) {
        towers[i].rect.left = 0;
        sfSprite_setTextureRect(towers[i].sprite, towers[i].rect);
    }
}
