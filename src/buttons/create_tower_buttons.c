/*
** EPITECH PROJECT, 2022
** create_tower_buttons.c
** File description:
** functions to create tower card buttons
*/

#include "defender.h"

void create_tac_button(buttons *buttons, sfVector2f pos, float resize,
int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = card;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    buttons[i].card_price = 600;
    create_sprite(buttons, i, scale, "src/images/TacCard.png");
    create_hovered_sprite(buttons, i, scale, "src/images/TacCard_hovered.png");
    create_pressed_sprite(buttons, i, scale, "src/images/TacCard_pressed.png");
}

void create_tesla_button(buttons *buttons, sfVector2f pos, float resize,
int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = card;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    buttons[i].card_price = 450;
    create_sprite(buttons, i, scale, "src/images/TeslaCard.png");
    create_hovered_sprite(buttons, i, scale, "src/images/Tesla_hovered.png");
    create_pressed_sprite(buttons, i, scale,
    "src/images/TeslaCard_pressed.png");
}

void create_sauda_button(buttons *buttons, sfVector2f pos, float resize,
int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = card;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    buttons[i].card_price = 1150;
    create_sprite(buttons, i, scale, "src/images/sauda.png");
    create_hovered_sprite(buttons, i, scale, "src/images/sauda_hovered.png");
    create_pressed_sprite(buttons, i, scale,
    "src/images/sauda_pressed.png");
}

void create_sniper_button(buttons *buttons, sfVector2f pos, float resize,
int i)
{
    sfVector2f scale = {resize, resize};

    buttons[i].button_type = card;
    buttons[i].pos = pos;
    buttons[i].is_hover = 1;
    buttons[i].is_pressed = 1;
    buttons[i].resize = resize;
    buttons[i].card_price = 350;
    create_sprite(buttons, i, scale, "src/images/sniper.png");
    create_hovered_sprite(buttons, i, scale, "src/images/sniper_hovered.png");
    create_pressed_sprite(buttons, i, scale,
    "src/images/sniper_pressed.png");
}