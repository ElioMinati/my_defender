/*
** EPITECH PROJECT, 2022
** display_radius.c
** File description:
** functions used to display radius of towers
*/

#include <stdlib.h>
#include "my.h"
#include "defender.h"

void display_radius(defender *objects, int rad)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(objects->window);
    sfVector2f pos = {mouse.x - rad, mouse.y - rad};
    sfCircleShape *radius =  sfCircleShape_create();

    sfCircleShape_setRadius(radius, rad);
    if (is_touching_illegal_item(objects) == 1)
        sfCircleShape_setFillColor(radius, sfColor_fromRGBA(255, 0, 0, 70));
    else
        sfCircleShape_setFillColor(radius, sfColor_fromRGBA(0, 0, 0, 50));
    sfCircleShape_setOutlineColor(radius, sfColor_fromRGBA(0, 0, 0, 144));
    sfCircleShape_setOutlineThickness(radius, 5);
    sfCircleShape_setPosition(radius, pos);
    sfRenderWindow_drawCircleShape(objects->window, radius, NULL);
    sfCircleShape_destroy(radius);
}

void display_tower_radius(defender *objects, int rad, tower tower)
{
    sfVector2f pos = {tower.pos.x + tower.offset.x - rad,
    tower.pos.y + tower.offset.y - rad};
    sfCircleShape *radius =  sfCircleShape_create();

    sfCircleShape_setRadius(radius, rad);
    sfCircleShape_setFillColor(radius, sfColor_fromRGBA(0, 0, 0, 50));
    sfCircleShape_setOutlineColor(radius, sfColor_fromRGBA(0, 0, 0, 144));
    sfCircleShape_setOutlineThickness(radius, 5);
    sfCircleShape_setPosition(radius, pos);
    sfRenderWindow_drawCircleShape(objects->window, radius, NULL);
    sfCircleShape_destroy(radius);
}

void display_radius_upgrade_text(int level, sfRenderWindow *win,
sfFont *font)
{
    char *str = malloc(8 * sizeof(char));
    sfText *text = sfText_create();
    sfVector2f pos = {1300, 665};

    str = my_strconcat("Range ", my_int_to_str(level + 1));
    if (level < 4)
        sfText_setString(text, str);
    else {
        sfText_setString(text, "Max Range");
        pos.x -= 45;
    }
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos);
    sfText_setOutlineThickness(text, 5);
    sfRenderWindow_drawText(win, text, NULL);
    sfText_destroy(text);
}

void set_text(sfText *text, sfVector2f pos)
{
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, pos);
    sfText_setOutlineThickness(text, 5);
}

void display_radius_upgrade_prices(defender *objects, tower tower)
{
    sfText *text = sfText_create();
    sfVector2f pos = {1385, 730};

    if (tower.rad_level < 4)
        sfText_setString(text,
        my_int_to_str(tower.radius_up_prices[tower.rad_level - 1]));
    else {
        sfText_destroy(text);
        return;
    }
    sfText_setFont(text, objects->cr_font);
    if (objects->game->money < tower.radius_up_prices[tower.rad_level - 1])
        sfText_setFillColor(text, sfRed);
    else
        sfText_setFillColor(text, sfWhite);
    set_text(text, pos);
    sfRenderWindow_drawText(objects->window, text, NULL);
    sfRenderWindow_drawSprite(objects->window,
    objects->game->first_up_gold_sprite, NULL);
    sfText_destroy(text);
}
