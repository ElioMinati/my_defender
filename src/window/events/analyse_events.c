/*
** EPITECH PROJECT, 2022
** analyse_events
** File description:
** functions used to analyse window events
*/

#include "defender.h"

static void analyse_end_events(defender *objects)
{
    if (objects->is_lose == 1) {
        detect_lose_button_hovering(objects);
        detect_lose_button_pressing(objects);
    }
    if (objects->is_win == 1) {
        detect_win_button_hovering(objects);
        detect_win_button_pressing(objects);
    }
}

static void analyse_upgrade_events(defender *objects)
{
    if (objects->is_upgrade == 1) {
        detect_upgrade_button_hovering(objects);
        detect_upgrade_button_pressing(objects);
    }
}

static void analyse_game_events(defender *objects)
{
    if (objects->is_dif_choice == 1) {
        detect_cmenu_button_hovering(objects);
        detect_cmenu_button_pressing(objects);
        detect_difficulty_hover(objects);
        detect_difficulty_choice(objects);
    }
    if (objects->is_in_game == 1 && objects->is_pause == 0
    && objects->is_win == 0 && objects->is_lose == 0) {
        detect_game_button_hovering(objects);
        detect_game_button_pressing(objects);
        detect_game_card_hovering(objects);
        detect_game_card_pressing(objects);
        detect_tower_pressing(objects->game->towers, objects);
    }
    if (objects->is_pause == 1) {
        detect_pause_button_hovering(objects);
        detect_pause_button_pressing(objects);
    }
    analyse_upgrade_events(objects);
    analyse_end_events(objects);
}

void analyse_events(defender *objects)
{
    if (objects->event.type == sfEvtClosed || objects->is_exit == 1)
        sfRenderWindow_close(objects->window);
    if (objects->is_main_menu == 1) {
        detect_menu_button_hovering(objects);
        detect_menu_button_pressing(objects);
    }
    if (objects->is_play_menu == 1) {
        detect_pmenu_button_hovering(objects);
        detect_pmenu_button_pressing(objects);
        detect_pmenu_case_hovering(objects);
        detect_pmenu_case_pressing(objects);
    }
    if (objects->is_info_menu == 1) {
        detect_pmenu_button_hovering(objects);
        detect_imenu_button_pressing(objects);
    }
    analyse_game_events(objects);
}
