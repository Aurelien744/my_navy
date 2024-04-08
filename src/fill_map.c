/*
** EPITECH PROJECT, 2024
** fill_map
** File description:
** my_navy
*/

#include "../include/my.h"

void fill_map(navy_t *boat, char *start, char *end)
{
    int ver = 0;
    int hor = 0;

    ver = is_vertical(start[0], end[0]);
    if (ver != 84) {
        ver_boat(ver, start[1], end[1], boat);
    } else {
        hor = is_horizontal(start[1], end[1]);
        hor = hor - 1;
        if (hor != 84) {
            hor_boat(hor, start[0], end[0], boat);
        }
    }
}
