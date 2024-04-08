/*
** EPITECH PROJECT, 2024
** horizontal_pos
** File description:
** my_navy
*/

#include "../include/my.h"

void hor_pos(int min, int max, int hor, navy_t *boat)
{
    int i = 0;

    for (i = min - 1; i != max - 1; i++) {
        boat->my_map[hor][i] = boat->size;
    }
    boat->my_map[hor][i] = boat->size;
}

void hor_boat(int hor, char s, char e, navy_t *boat)
{
    int start = s - 64;
    int end = e - 64;

    if (start < end) {
        hor_pos(start, end, hor, boat);
    } else {
        hor_pos(end, start, hor, boat);
    }
}

int is_horizontal(char s, char e)
{
    int idx = 0;

    if (s != e) {
        return (84);
    } else {
        idx = s - 48;
    }
    return (idx);
}
