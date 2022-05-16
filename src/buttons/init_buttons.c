/*
** EPITECH PROJECT, 2022
** buttons.c
** File description:
** create a button
*/

#include "defender.h"

void init_menu_buttons(buttons *menu_buttons)
{
    sfVector2f exit_pos = {20, 930};
    sfVector2f play_pos = {750, 575};
    sfVector2f info_pos = {1815, 20};

    menu_buttons->nb_buttons = 3;
    create_exit_button(menu_buttons, exit_pos, 1, 0);
    create_play_button(menu_buttons, play_pos, 0.55, 1);
    create_info_button(menu_buttons, info_pos, 1, 2);
}

void init_play_menu_buttons(buttons *play_menu_buttons)
{
    sfVector2f exit_pos = {20, 930};
    sfVector2f back_pos = {20, 20};

    play_menu_buttons->nb_buttons = 2;
    create_exit_button(play_menu_buttons, exit_pos, 1, 0);
    create_back_button(play_menu_buttons, back_pos, 0.75, 1);
}

void init_cases(map_case *map_case)
{
    sfVector2f case_pos = {200, 200};
    sfVector2f case2_pos = {800, 200};
    sfVector2f case3_pos = {1400, 200};

    map_case->nb_cases = 3;
    create_case(map_case, 0, case_pos, "src/images/map1.png");
    create_case(map_case, 1, case2_pos, "src/images/map2.png");
    create_case(map_case, 2, case3_pos, "src/images/map3.png");
}

void init_difficulty_menu_buttons(buttons *buttons)
{
    sfVector2f easy_pos = {150, 400};
    sfVector2f inter_pos = {750, 400};
    sfVector2f hard_pos = {1350, 400};

    buttons->nb_buttons = 3;
    create_easy_button(buttons, easy_pos, 0.55, 0);
    create_inter_button(buttons, inter_pos, 0.55, 1);
    create_hard_button(buttons, hard_pos, 0.55, 2);

}

void init_buttons(defender *objects)
{
    init_menu_buttons(objects->menu_buttons);
    init_play_menu_buttons(objects->play_menu_buttons);
    init_difficulty_menu_buttons(objects->dif_menu_buttons);
    init_cases(objects->map_case);
}
