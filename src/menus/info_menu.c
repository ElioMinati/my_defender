/*
** EPITECH PROJECT, 2022
** info_menu.c
** File description:
** functions used to display the info menu
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "defender.h"

static char *read_file(char *filename, int size)
{
    int fd = open(filename, O_RDONLY);
    char *buf = malloc ((size + 1) * sizeof(char));

    read(fd, buf, size);
    buf[size] = '\0';
    close(fd);
    return buf;
}

static void display_text(sfRenderWindow *win, sfFont *font)
{
    char *buf = read_file("src/menus/how_to_play.txt", 235);
    sfText *text = sfText_create();
    sfVector2f pos_text = {100, 100};

    sfText_setString(text, buf);
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlue);
    sfText_setCharacterSize(text, 50);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos_text);
    sfText_setOutlineThickness(text, 5);
    sfRenderWindow_drawText(win, text, NULL);
    sfText_destroy(text);
}

void display_info_menu(defender *objects)
{
    display_background(objects->window, "src/images/blurry_tropico.png");
    display_buttons(objects->window, objects->play_menu_buttons);
    display_text(objects->window, objects->btd_font);
}
