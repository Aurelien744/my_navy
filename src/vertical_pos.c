/*
** EPITECH PROJECT, 2024
** vertical_pos
** File description:
** my_navy
*/

#include "../include/my.h"

void ver_pos(int min, int max, int ver, navy_t *boat)
{
    ver = ver - 1;
    for (int i = min - 1; i != max; i++) {
        boat->my_map[i][ver] = boat->size;
    }
}

int is_vertical(char s, char e)
{
    int idx = 0;

    if (s != e) {
        return (84);
    } else {
        idx = s - 64;
    }
    return (idx);
}

void ver_boat(int ver, char s, char e, navy_t *boat)
{
    int start = s - 48;
    int end = e - 48;

    if (start < end) {
        ver_pos(start, end, ver, boat);
    } else {
        ver_pos(end, start, ver, boat);
    }
}
