/*
** EPITECH PROJECT, 2022
** create_difficulty_buttons
** File description:
** functions used to create the difficulty buttons
*/

#include "defender.h"

void create_easy_button(buttons *buttons, sfVector2f pos, float resize, int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/easy.png");
    create_hovered_sprite(buttons, i, scale, "src/images/easy_pressed.png");
    create_pressed_sprite(buttons, i, scale, "src/images/easy_pressed.png");
}

void create_inter_button(buttons *buttons, sfVector2f pos, float resize, int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/inter.png");
    create_hovered_sprite(buttons, i, scale, "src/images/inter_pressed.png");
    create_pressed_sprite(buttons, i, scale, "src/images/inter_pressed.png");
}

void create_hard_button(buttons *buttons, sfVector2f pos, float resize, int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/hard.png");
    create_hovered_sprite(buttons, i, scale, "src/images/hard_pressed.png");
    create_pressed_sprite(buttons, i, scale, "src/images/hard_pressed.png");
}
