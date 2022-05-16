/*
** EPITECH PROJECT, 2022
** create_button.c
** File description:
** create different buttons
*/

#include "defender.h"

void create_exit_button(buttons *buttons, sfVector2f pos, float resize, int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = quit;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/exit.png");
    create_hovered_sprite(buttons, i, scale, "src/images/hovered_exit.png");
    create_pressed_sprite(buttons, i, scale, "src/images/pressed_exit.png");
}

void create_back_button(buttons *buttons, sfVector2f pos, float resize, int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = back;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/back.png");
    create_hovered_sprite(buttons, i, scale, "src/images/hovered_back.png");
    create_pressed_sprite(buttons, i, scale, "src/images/pressed_back.png");
}

void create_close_button(buttons *buttons, sfVector2f pos, float resize, int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = closed;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/close.png");
    create_hovered_sprite(buttons, i, scale, "src/images/close.png");
    create_pressed_sprite(buttons, i, scale, "src/images/close.png");
}

void create_info_button(buttons *buttons, sfVector2f pos, float resize, int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = help;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/info.png");
    create_hovered_sprite(buttons, i, scale, "src/images/hovered_info.png");
    create_pressed_sprite(buttons, i, scale, "src/images/pressed_info.png");
}

void create_play_button(buttons *buttons, sfVector2f pos, float resize, int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = play;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    create_sprite(buttons, i, scale, "src/images/cr_play.png");
    create_hovered_sprite(buttons, i, scale, "src/images/cr_play_hovered.png");
    create_pressed_sprite(buttons, i, scale, "src/images/cr_play_pressed.png");
}
