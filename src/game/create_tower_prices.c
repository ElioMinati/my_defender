/*
** EPITECH PROJECT, 2022
** create_tower_prices
** File description:
** functions used to create a tower price
*/

#include "my.h"
#include "defender.h"

void create_price(buttons *buttons, int index, int price,
sfVector2f pos)
{
    buttons[index].card_price = price;
    buttons[index].text = sfText_create();
    sfText_setString(buttons[index].text, my_int_to_str(price));
    sfText_setCharacterSize(buttons[index].text, 20);
    sfText_setPosition(buttons[index].text, pos);
    sfText_setOutlineThickness(buttons[index].text, 5);
}
