/*
** EPITECH PROJECT, 2024
** get_signal
** File description:
** my_navy
*/

#include "../include/my.h"
#include "../include/struct.h"

void get_sig(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR1) {
        global = 1;
    }
    if (signum == SIGUSR2) {
        global = 0;
    }
}
