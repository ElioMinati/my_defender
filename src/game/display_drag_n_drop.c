/*
** EPITECH PROJECT, 2022
** display_drag_n_drop
** File description:
** displays the towers on drag n drop
*/

#include "defender.h"

void display_tesla(defender *objects)
{
    sfTexture *texture =
    sfTexture_createFromFile("src/images/tower1.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect rect;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(objects->window);
    sfVector2f pos = {mouse.x - 37, mouse.y - 130};
    sfVector2f resize = {1.2, 1.2};

    rect.width = 74;
    rect.top = 0;
    rect.left = 0;
    rect.height = 135;
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, resize);
    sfRenderWindow_drawSprite(objects->window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void display_tac(defender *objects)
{
    sfTexture *texture =
    sfTexture_createFromFile("src/images/tac.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(objects->window);
    sfVector2f pos = {mouse.x - 55, mouse.y - 80};
    sfIntRect rect;

    rect.width = 108;
    rect.top = 0;
    rect.left = 0;
    rect.height = 131;
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(objects->window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void display_sauda(defender *objects)
{
    sfTexture *texture =
    sfTexture_createFromFile("src/images/sauda_spritesheet.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(objects->window);
    sfVector2f pos = {mouse.x - 125, mouse.y - 90};
    sfIntRect rect;

    rect.width = 250;
    rect.top = 0;
    rect.left = 0;
    rect.height = 179;
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(objects->window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void display_sniper(defender *objects)
{
    sfTexture *texture =
    sfTexture_createFromFile("src/images/sniper_spritesheet.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(objects->window);
    sfVector2f pos = {mouse.x - 90, mouse.y - 68};
    sfIntRect rect;

    rect.width = 140;
    rect.top = 0;
    rect.left = 0;
    rect.height = 136;
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(objects->window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}