/*
** EPITECH PROJECT, 2024
** exmpty_tab
** File description:
** my_navy
*/

#include "../include/my.h"
#include "../include/struct.h"
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void empty_maps(navy_t *boat)
{
    my_map(boat);
    enemy_map(boat);
    display_mmap(boat);
    display_emaps(boat);
}

void my_map(navy_t *boat)
{
    int i = 0;

    boat->my_map = NULL;
    boat->my_map = malloc(sizeof(char *) * 9);
    for (i = 0; i < 8; i++) {
        boat->my_map[i] = malloc(sizeof(char) * 8 + 1);
        for (int j = 0; j < 8; j++) {
            boat->my_map[i][j] = '.';
        }
        boat->my_map[i][8] = '\0';
    }
    boat->my_map[8] = NULL;
}

void enemy_map(navy_t *boat)
{
    int i;

    boat->enemy_map = NULL;
    boat->enemy_map = malloc(sizeof(char *) * 9);
    for (i = 0; i < 8; i++) {
        boat->enemy_map[i] = malloc(sizeof(char) * 8 + 1);
        for (int j = 0; j < 8; j++) {
            boat->enemy_map[i][j] = '.';
        }
        boat->enemy_map[i][8] = '\0';
    }
    boat->enemy_map[8] = NULL;
}
