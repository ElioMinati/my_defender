/*
** EPITECH PROJECT, 2022
** verify_tower_placing.c
** File description:
** functions used to verify tower placing on all maps
*/

#include "defender.h"

static int verify_tower_placing_first_sec(sfVector2i mouse)
{
    if (mouse.x > 180 &&  mouse.x < 350 && mouse.y < 850 && mouse.y > 480)
        return 1;
    if (mouse.x > 180 && mouse.x < 950 && mouse.y > 480 && mouse.y < 620)
        return 1;
    if (mouse.x > 950 && mouse.x < 1100 && mouse.y > 220 && mouse.y < 600)
        return 1;
    if (mouse.x > 950 && mouse.x < 1290 && mouse.y > 220 && mouse.y < 350)
        return 1;
    if (mouse.x > 1120 && mouse.x < 1290 && mouse.y > 220 && mouse.y < 750)
        return 1;
    if (mouse.x > 655 && mouse.x < 1150 && mouse.y > 650 && mouse.y < 770)
        return 1;
    if (mouse.x > 640 && mouse.x < 780 && mouse.y > 700)
        return 1;
    return 0;
}

int verify_tower_placing_first(defender *objects)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(objects->window);

    if (mouse.x > 1565 || mouse.y < 100)
        return 1;
    if (mouse.x > 450 && mouse.x < 600 && mouse.y < 850)
        return 1;
    if (mouse.x < 890 && mouse.y > 310 && mouse.y < 450)
        return 1;
    if (mouse.x > 450 && mouse.x < 890 && mouse.y < 180)
        return 1;
    if (mouse.x > 715 && mouse.x < 890 && mouse.y < 450)
        return 1;
    if (mouse.x > 180 &&  mouse.x < 600 && mouse.y < 850 && mouse.y > 730)
        return 1;
    return verify_tower_placing_first_sec(mouse);
}

static int verify_tower_placing_secondmo(sfVector2i mouse)
{
    if (mouse.x > 320 && mouse.x < 460 && mouse.y < 380)
        return 1;
    if (mouse.x > 320 && mouse.x < 800 && mouse.y < 180)
        return 1;
    if (mouse.x > 680 && mouse.x < 800 && mouse.y < 800)
        return 1;
    if (mouse.x > 680 && mouse.x < 1150 && mouse.y < 800 && mouse.y > 700)
        return 1;
    if (mouse.x > 1200 && mouse.x < 1500 && mouse.y < 800 && mouse.y > 530)
        return 1;
    if (mouse.x > 1300 && mouse.y > 700)
        return 1;
    return 0;
}

int verify_tower_placing_secondm(sfVector2i mouse)
{
    if (mouse.x > 1050 && mouse.x < 1170 && mouse.y < 750 && mouse.y > 530)
        return 1;
    if (mouse.x > 900 && mouse.x < 1120 && mouse.y < 620 && mouse.y > 510)
        return 1;
    if (mouse.x > 860 && mouse.x < 980 && mouse.y < 590 && mouse.y > 280)
        return 1;
    if (mouse.x > 880 && mouse.x < 1350 && mouse.y < 380 && mouse.y > 270)
        return 1;
    if (mouse.x > 1050 && mouse.x < 1430 && mouse.y < 350)
        return 1;
    if (mouse.x > 1050 && mouse.x < 1180 && mouse.y < 500)
        return 1;
    if (mouse.x > 1080 && mouse.y < 520 && mouse.y > 410)
        return 1;
    if (mouse.x > 800 && mouse.x < 980 && mouse.y < 320)
        return 1;
    if (mouse.x < 300 && mouse.y > 800)
        return 1;
    return verify_tower_placing_secondmo(mouse);
}
