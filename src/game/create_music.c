/*
** EPITECH PROJECT, 2022
** create_music
** File description:
** functions used to handle in-game music
*/

#include <SFML/Audio.h>
#include "defender.h"

void create_bg_music(defender *objects)
{
    objects->bg_music = sfMusic_createFromFile("src/sounds/conversations.ogg");
    sfMusic_setLoop(objects->bg_music, sfTrue);
    sfMusic_play(objects->bg_music);
}

void init_effects(game *game)
{
    game->win = sfMusic_createFromFile("src/sounds/heheheha.ogg");
    game->lose = sfMusic_createFromFile("src/sounds/lose.ogg");
}
