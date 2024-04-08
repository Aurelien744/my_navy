/*
** EPITECH PROJECT, 2024
** display_maps
** File description:
** navy
*/

#include "../include/my.h"
#include "../include/struct.h"
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void my_put_space(int y)
{
    if (y < 7)
        my_putchar(' ');
}

void display_mmap(navy_t *boat)
{
    char nb = '1';

    my_putstr("my navy:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; boat->my_map[i] != NULL; i++) {
        my_putchar(nb);
        my_putchar('|');
        nb++;
        for (int y = 0; boat->my_map[i][y] != '\0'; y++) {
            my_putchar(boat->my_map[i][y]);
            my_put_space(y);
        }
        my_putchar('\n');
    }
    my_putchar('\n');
}

void display_emaps(navy_t *boat)
{
    char nb = '1';

    my_putstr("enemy navy:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; boat->enemy_map[i] != NULL; i++) {
        my_putchar(nb);
        my_putchar('|');
        nb++;
        for (int y = 0; boat->enemy_map[i][y] != '\0'; y++) {
            my_putchar(boat->enemy_map[i][y]);
            my_put_space(y);
        }
        my_putchar('\n');
    }
    my_putchar('\n');
}
