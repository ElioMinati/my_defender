/*
** EPITECH PROJECT, 2022
** round_handling.c
** File description:
** functions used to handle the current round
*/

#include "defender.h"

static void handle_even_more_rounds(game *game)
{
    if (game->current_round == 18)
        init_eighteen_round(game);
    if (game->current_round == 19)
        init_nineteen_round(game);
    if (game->current_round == 20)
        init_twenty_round(game);
    if (game->current_round == 21)
        init_twenty_o_round(game);
    if (game->current_round == 22)
        init_twenty_to_round(game);
    if (game->current_round == 23)
        init_twenty_te_round(game);
    if (game->current_round == 24)
        init_twenty_fr_round(game);
    if (game->current_round == 25)
        init_twenty_fv_round(game);
    if (game->current_round > 25)
        init_freeplay_bloons(game, game->current_round - 25);
    transfer_bloon_pos(game);
}

static void handle_more_rounds(game *game)
{
    if (game->current_round == 9)
        init_nine_round(game);
    if (game->current_round == 10)
        init_ten_round(game);
    if (game->current_round == 11)
        init_eleven_round(game);
    if (game->current_round == 12)
        init_twelve_round(game);
    if (game->current_round == 13)
        init_thirteen_round(game);
    if (game->current_round == 14)
        init_fourteen_round(game);
    if (game->current_round == 15)
        init_fifteen_round(game);
    if (game->current_round == 16)
        init_sixteen_round(game);
    if (game->current_round == 17)
        init_seventeen_round(game);
    handle_even_more_rounds(game);
}

void handle_rounds(game *game)
{
    if (game->current_round > 1)
        game->money += 200;
    if (game->current_round == 1)
        init_first_round(game);
    if (game->current_round == 2)
        init_second_round(game);
    if (game->current_round == 3)
        init_third_round(game);
    if (game->current_round == 4)
        init_fourth_round(game);
    if (game->current_round == 5)
        init_fifth_round(game);
    if (game->current_round == 6)
        init_six_round(game);
    if (game->current_round == 7)
        init_seven_round(game);
    if (game->current_round == 8)
        init_eight_round(game);
    handle_more_rounds(game);
}

int is_round_over(game *game)
{
    if (game->bloons == NULL)
        return 1;
    for (int i = 0; i < game->bloons->nb_bloons; ++i) {
        if (game->bloons[i].is_pop == 0)
            return 0;
    }
    return 1;
}
