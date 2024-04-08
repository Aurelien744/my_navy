/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-pierre-louis.schorsch
** File description:
** main
*/

#include "../include/my.h"
#include "../include/struct.h"

int global = 0;

int main(int argc, char **argv)
{
    navy_t *boat = malloc(sizeof(navy_t));
    int i = -1;
    struct sigaction sa;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help();
        return 0;
    }
    if (argc > 3 || argc < 2) {
        write(2, "bad arguments\n", 14);
        return 84;
    } else {
        i = navy(argc, argv, boat);
    }
    if (i == 84)
        return 84;
    sa.sa_sigaction = get_sig;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    game_loop(boat);
}
