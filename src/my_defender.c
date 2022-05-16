/*
** EPITECH PROJECT, 2022
** my_defender.c
** File description:
** my_defender main file
*/

#include <stdlib.h>
#include "defender.h"

static void init_status(defender *objects)
{
    objects->is_main_menu = 1;
    objects->is_pause = 0;
    objects->is_play_menu = 0;
    objects->is_info_menu = 0;
    objects->is_in_game = 0;
    objects->is_exit = 0;
    objects->is_win = 0;
    objects->is_lose = 0;
    objects->is_upgrade = 0;
    objects->map_choice = 0;
    objects->is_dif_choice = 0;
    objects->is_init_game = 0;
}

void init_defender(defender *objects)
{
    objects->window = window_create(1920, 1080, 32);
    objects->clock = sfClock_create();
    objects->btd_font = sfFont_createFromFile("src/fonts/oetzyp.ttf");
    objects->cr_font = sfFont_createFromFile("src/fonts/crfont.ttf");
    objects->menu_buttons = malloc(3 * sizeof(buttons));
    objects->play_menu_buttons = malloc(2 * sizeof(buttons));
    objects->map_case = malloc(3 * sizeof(map_case));
    objects->dif_menu_buttons = malloc(3 * sizeof(buttons));
    objects->game = malloc(sizeof(*objects->game));
    init_buttons(objects);
    init_status(objects);
    create_bg_music(objects);
}

void display_game(defender *objects)
{
    if (objects->is_main_menu == 1)
        display_main_menu(objects);
    if (objects->is_play_menu == 1)
        display_play_menu(objects);
    if (objects->is_info_menu == 1)
        display_info_menu(objects);
    if (objects->is_dif_choice == 1)
        display_difficulty_menu(objects);
    if (objects->is_in_game == 1)
        display_vgame(objects);
}

void wait_for_button_release(sfRenderWindow *win, sfEvent event)
{
    while (event.type == sfEvtMouseButtonPressed)
        sfRenderWindow_pollEvent(win, &event);
}

void my_defender(void)
{
    defender *objects = malloc(sizeof(*objects));

    init_defender(objects);
    while (sfRenderWindow_isOpen(objects->window)) {
        sfRenderWindow_display(objects->window);
        sfRenderWindow_clear(objects->window, sfBlack);
        while (sfRenderWindow_pollEvent(objects->window, &objects->event))
            analyse_events(objects);
        display_game(objects);
    }
    destroy_struct(objects);
}
