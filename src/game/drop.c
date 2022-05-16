/*
** EPITECH PROJECT, 2022
** drop.c
** File description:
** functions used to drop the tower after drag
*/

#include "defender.h"

void detect_drop(defender *objects, int id, int price)
{
    if (objects->event.type == sfEvtMouseButtonPressed &&
    objects->game->card_id == id &&
    objects->game->money >= price && is_touching_illegal_item(objects) == 0) {
        place_tower(objects);
        objects->game->card_id = -1;
    }
}
