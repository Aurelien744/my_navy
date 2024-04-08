/*
** EPITECH PROJECT, 2024
** game_loop
** File description:
** my_navy
*/

#include "../include/my.h"

int count_x(char **map, int i, int j, int x_nb)
{
    if (map[i][j] == 'x') {
        x_nb++;
    }
    return (x_nb);
}

int x_in_map(char **map)
{
    int x_nb = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            x_nb = count_x(map, i, j, x_nb);
        }
    }
    return (x_nb);
}

void display_maps(navy_t *boat)
{
    display_mmap(boat);
    display_emaps(boat);
}

void end_game(navy_t *boat)
{
    if (x_in_map(boat->enemy_map) == 14) {
        display_maps(boat);
        my_putstr("I won\n");
    } else {
        display_maps(boat);
        my_putstr("Enemy won\n");
    }
}

int game_loop(navy_t *boat)
{
    char *input;
    int idx = 0;

    while (x_in_map(boat->enemy_map) != 14 && x_in_map(boat->my_map) != 14) {
        if (idx % 2 == 0 && idx != 0)
            display_maps(boat);
        boat->coord = NULL;
        if (boat->boule == 0) {
            my_attack(boat);
        } else {
            my_defense(boat);
        }
        boat->boule = !boat->boule;
        idx++;
    }
    end_game(boat);
}
