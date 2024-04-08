/*
** EPITECH PROJECT, 2024
** player_two
** File description:
** navy
*/

#include "../include/my.h"
#include "../include/struct.h"
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void sig_handler(int num)
{
    write(1, "\nsuccessfully connected\n", 24);
}

int p_two_connection(int ac, char **av, navy_t *boat)
{
    struct sigaction sa;

    boat->enemy_pid = my_getnbr(av[1]);
    boat->my_pid = getpid();
    kill(boat->enemy_pid, SIGUSR2);
    signal(SIGUSR1, sig_handler);
    pause();
    return (0);
}

int player_two(int ac, char **av, navy_t *boat)
{
    p_two_connection(ac, av, boat);
    return (0);
}
