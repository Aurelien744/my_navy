/*
** EPITECH PROJECT, 2024
** my_attack
** File description:
** my_navy
*/

#include "../include/my.h"
#include "../include/struct.h"

void wrong_position(int x, int y, navy_t *boat)
{
    my_putstr("\nwrong position\n\n");
    my_attack(boat);
}

int my_attack(navy_t *boat)
{
    char buffer[32];
    char *b = buffer;
    size_t bufsize = 32;
    size_t characters;
    int x = 0;
    int y = 0;

    my_putstr("attack: ");
    characters = getline(&b, &bufsize, stdin);
    if (characters > 0 && b[characters - 1] == '\n')
        b[characters - 1] = '\0';
    boat->coord = buffer;
    x = buffer[0] - 64;
    y = buffer[1] - 48;
    if ((x <= 0 || x >= 9 || y <= 0 || y >= 9) ||
    (buffer[2] != '\n' && buffer[2] != '\0')) {
        wrong_position(x, y, boat);
        return 0;
    }
    send_attack(x, y, boat);
}

void send_attack(int x, int y, navy_t *boat)
{
    for (int i = 0; i < 8; i++) {
        if (i < x) {
            kill(boat->enemy_pid, SIGUSR1);
        } else {
            kill(boat->enemy_pid, SIGUSR2);
        }
        usleep(5000);
    }
    for (int i = 0; i < 8; i++) {
        if (i < y) {
            kill(boat->enemy_pid, SIGUSR1);
        } else {
            kill(boat->enemy_pid, SIGUSR2);
        }
        usleep(5000);
    }
    hit_or_not(boat);
}

void hit(navy_t *boat)
{
    my_putchar('\n');
    my_putstr(boat->coord);
    write(1, ": hit\n\n", 7);
    boat->enemy_map[boat->coord[1] - 49][boat->coord[0] - 65] = 'x';
}

void missed(navy_t *boat)
{
    my_putchar('\n');
    my_putstr(boat->coord);
    write(1, ": missed\n\n", 10);
    if (boat->enemy_map[boat->coord[1] - 49][boat->coord[0] - 65] == 'o' ||
    boat->enemy_map[boat->coord[1] - 49][boat->coord[0] - 65] == 'x') {
        return;
    }
    if (boat->enemy_map[boat->coord[1] - 49][boat->coord[0] - 65] == '.') {
        boat->enemy_map[boat->coord[1] - 49][boat->coord[0] - 65] = 'o';
    }
}
