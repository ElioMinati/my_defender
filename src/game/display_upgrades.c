/*
** EPITECH PROJECT, 2022
** display_upgrades.c
** File description:
** functions used to display upgrades
*/

#include <stdlib.h>
#include "my.h"
#include "defender.h"

static void display_hover_rect(defender *objects, sfVector2f pos)
{
    sfVector2f size = {358, 135};
    sfRectangleShape *rect =  sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, 100));
    sfRectangleShape_setPosition(rect, pos);
    sfRenderWindow_drawRectangleShape(objects->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

static void display_tesla_upgrade_text(int level, sfRenderWindow *win,
sfFont *font)
{
    char *str = malloc(8 * sizeof(char));
    sfText *text = sfText_create();
    sfVector2f pos = {1330, 820};

    str = my_strconcat("level ", my_int_to_str(level + 1));
    if (level < 4)
        sfText_setString(text, str);
    else {
        sfText_setString(text, "Max level");
        pos.x -= 50;
    }
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos);
    sfText_setOutlineThickness(text, 5);
    sfRenderWindow_drawText(win, text, NULL);
    sfText_destroy(text);
}

void display_upgrade_hover(defender *objects, int index)
{
    int nb = objects->game->towers[index].upgrade_buttons->nb_buttons;

    for (int i = 0; i < nb; ++i) {
        if (objects->game->towers[index].upgrade_buttons[i].is_hover == 1) {
            display_hover_rect(objects,
            objects->game->towers[index].upgrade_buttons[i].pos);
        }
    }
}

void display_upgrade_prices(defender *objects, tower tower)
{
    sfText *text = sfText_create();
    sfVector2f pos = {1385, 885};

    if (tower.level < 4)
        sfText_setString(text,
        my_int_to_str(tower.upgrade_prices[tower.level - 1]));
    else {
        sfText_destroy(text);
        return;
    }
    sfText_setFont(text, objects->cr_font);
    if (objects->game->money < tower.upgrade_prices[tower.level - 1])
        sfText_setFillColor(text, sfRed);
    else
        sfText_setFillColor(text, sfWhite);
    set_text(text, pos);
    sfRenderWindow_drawText(objects->window, text, NULL);
    sfRenderWindow_drawSprite(objects->window, objects->game->up_gold_sprite,
    NULL);
    sfText_destroy(text);
}

void display_upgrade_menu(defender *objects)
{
    int index;

    if (objects->is_upgrade == 1) {
        index = objects->game->tower_to_upgrade;
        display_tower_radius(objects, objects->game->towers[index].rad,
        objects->game->towers[index]);
        sfRenderWindow_drawSprite(objects->window,
        objects->game->upgrade_sprite, NULL);
        display_buttons(objects->window, objects->game->upgrade_buttons);
        display_upgrade_hover(objects, index);
        display_tesla_upgrade_text(objects->game->towers[index].level,
        objects->window, objects->cr_font);
        display_upgrade_prices(objects, objects->game->towers[index]);
        display_radius_upgrade_prices(objects,
        objects->game->towers[index]);
        display_radius_upgrade_text(objects->game->towers[index].rad_level,
        objects->window, objects->cr_font);
    }
}
