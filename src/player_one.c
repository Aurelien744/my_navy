/*
** EPITECH PROJECT, 2024
** player_one
** File description:
** navy
*/

#include "../include/my.h"
#include "../include/struct.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>

void handler(int num, siginfo_t *info, void *context)
{
    write(1, "\nenemy connected\n", 17);
    global = info->si_pid;
}

int p_one_connexion(navy_t *boat)
{
    struct sigaction sa;

    boat->my_pid = getpid();
    write(1, "my_pid: ", 9);
    my_put_nbr(boat->my_pid);
    write(1, "\n", 1);
    write(1, "\nwaiting for enemy connection...\n", 33);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    boat->enemy_pid = global;
    kill(boat->enemy_pid, SIGUSR1);
    sa.sa_sigaction = get_sig;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    return (0);
}

int player_one(navy_t *boat)
{
    p_one_connexion(boat);
    return (0);
}
