/*
** EPITECH PROJECT, 2022
** create_game_button
** File description:
** functions to create game buttons
*/

#include "defender.h"

void create_settings_button(buttons *buttons, sfVector2f pos, float resize,
int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = paused;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/settings.png");
    create_hovered_sprite(buttons, i, scale, "src/images/hovered_settings.png");
    create_pressed_sprite(buttons, i, scale, "src/images/pressed_settings.png");
}

void create_home_button(buttons *buttons, sfVector2f pos, float resize,
int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = paused;
    buttons[i].pos = pos;
    buttons[i].is_hover = 0;
    buttons[i].is_pressed = 0;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/home.png");
    create_hovered_sprite(buttons, i, scale, "src/images/hovered_home.png");
    create_pressed_sprite(buttons, i, scale, "src/images/pressed_home.png");
}

void create_inv_button(buttons *button, sfVector2f pos, int width,
int height)
{
    button->button_type = tesla;
    button->pos = pos;
    button->width = width;
    button->height = height;
}

void create_play_round_button(buttons *buttons, sfVector2f pos,
float resize, int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = play;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/play_round.png");
    create_hovered_sprite(buttons, i, scale,
    "src/images/hovered_play_rd.png");
    create_pressed_sprite(buttons, i, scale,
    "src/images/pressed_play_round.png");
}

void create_freeplay_button(buttons *buttons, sfVector2f pos, float resize,
int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = paused;
    buttons[i].pos = pos;
    buttons[i].is_hover = 0;
    buttons[i].is_pressed = 0;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/freeplay.png");
    create_hovered_sprite(buttons, i, scale, "src/images/freeplay_hovered.png");
    create_pressed_sprite(buttons, i, scale, "src/images/freeplay_pressed.png");
}
