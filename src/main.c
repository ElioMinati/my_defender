/*
** EPITECH PROJECT, 2022
** main
** File description:
** main for defender
*/

#include "my.h"
#include "defender.h"

static void display_help(void)
{
    my_putstr("USAGE:\n");
    my_putstr("    ./my_defender\n");
    my_putstr("DESCRIPTION:\n");
    my_putstr(
    "   tower defense, the goal is to not lose all your lives\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h")) {
        display_help();
        return 0;
    }
    my_defender();
    return 0;
}
