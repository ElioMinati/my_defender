/*
** EPITECH PROJECT, 2022
** create_button_sprite
** File description:
** functions related to button sprite creation
*/

#include "defender.h"

void create_sprite(buttons *buttons, int i,
sfVector2f scale, char *texture_path)
{
    buttons[i].texture = sfTexture_createFromFile(texture_path, NULL);
    buttons[i].sprite = sfSprite_create();
    sfSprite_setPosition(buttons[i].sprite, buttons[i].pos);
    sfSprite_setTexture(buttons[i].sprite, buttons[i].texture,
    sfFalse);
    sfSprite_setScale(buttons[i].sprite, scale);

}

void create_hovered_sprite(buttons *buttons, int i,
sfVector2f scale, char *texture_path)
{
    buttons[i].hovered_texture = sfTexture_createFromFile(texture_path, NULL);
    buttons[i].hovered_sprite = sfSprite_create();
    sfSprite_setPosition(buttons[i].hovered_sprite, buttons[i].pos);
    sfSprite_setTexture(buttons[i].hovered_sprite, buttons[i].hovered_texture,
    sfFalse);
    sfSprite_setScale(buttons[i].hovered_sprite, scale);
}

void create_pressed_sprite(buttons *buttons, int i,
sfVector2f scale, char *texture_path)
{
    buttons[i].pressed_texture = sfTexture_createFromFile(texture_path, NULL);
    buttons[i].pressed_sprite = sfSprite_create();
    sfSprite_setPosition(buttons[i].pressed_sprite, buttons[i].pos);
    sfSprite_setTexture(buttons[i].pressed_sprite, buttons[i].pressed_texture,
    sfFalse);
    sfSprite_setScale(buttons[i].pressed_sprite, scale);
}
