/*
** EPITECH PROJECT, 2024
** my_defense
** File description:
** my_navy
*/

#include "../include/my.h"
#include "../include/struct.h"

void print_result(int letter, int number)
{
    my_putchar(letter + 64);
    my_putchar(number + 48);
}

void stock_pose(int letter, int number, navy_t *boat)
{
    int cols = letter - 1;
    int lines = number - 1;

    if (boat->my_map[lines][cols] == '.') {
        print_result(letter, number);
        my_putstr(": missed\n\n");
        boat->my_map[lines][cols] = 'o';
        kill(boat->enemy_pid, SIGUSR1);
    }
}

void stock_pos(int letter, int number, navy_t *boat)
{
    int cols = letter - 1;
    int lines = number - 1;

    usleep(1000000);
    if (boat->my_map[lines][cols] == 'o' || boat->my_map[lines][cols] == 'x') {
        print_result(letter, number);
        my_putstr(": missed\n\n");
        kill(boat->enemy_pid, SIGUSR1);
    }
    if (boat->my_map[lines][cols] > '0' && boat->my_map[lines][cols] < '9') {
        print_result(letter, number);
        my_putstr(": hit\n\n");
        boat->my_map[lines][cols] = 'x';
        kill(boat->enemy_pid, SIGUSR2);
    }
    stock_pose(letter, number, boat);
}

int my_defense(navy_t *boat)
{
    int x = 0;
    int y = 0;
    int nb_sig = 0;

    my_putstr("waiting for enemy's attack...\n\n");
    while (nb_sig < 16) {
        pause();
        if (nb_sig < 8) {
            x += global;
        } else {
            y += global;
        }
        nb_sig++;
    }
    stock_pos(x, y, boat);
    return (0);
}

int hit_or_not(navy_t *boat)
{
    pause();
    if (global == 0)
        hit(boat);
    if (global == 1)
        missed(boat);
    return (0);
}
