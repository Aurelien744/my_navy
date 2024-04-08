/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-pierre-louis.schorsch
** File description:
** help
*/

#include "../include/my.h"

int help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./navy [first_player_pid] navy_positions\n", 42);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\tfirst_player_pid: only for the 2nd player.", 43);
    write(1, "pid of the first play\n", 22);
    write(1, "\tnavy_positions: file representing the ", 39);
    write(1, "positions of the ships.\n", 24);
}
