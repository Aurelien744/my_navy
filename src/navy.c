/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-pierre-louis.schorsch
** File description:
** navy
*/

#include "../include/my.h"
#include "../include/struct.h"

void part_pone(navy_t *boat)
{
    boat->boule = 0;
    player_one(boat);
    display_mmap(boat);
    display_emaps(boat);
}

void part_ptwo(navy_t *boat, int ac, char **av)
{
    boat->boule = 1;
    player_two(ac, av, boat);
    display_mmap(boat);
    display_emaps(boat);
}

int navy(int argc, char **argv, navy_t *boat)
{
    int i = -1;

    my_map(boat);
    enemy_map(boat);
    if (argc == 2) {
        i = par_fil(argv[1], boat);
        if (i == 84) {
            return 84;
        } else
            part_pone(boat);
    }
    if (argc == 3) {
        i = par_fil(argv[2], boat);
        if (i == 84) {
            return 84;
        } else
            part_ptwo(boat, argc, argv);
    return 0;
    }
}
