/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-pierre-louis.schorsch
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #define _GNU_SOURCE
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <signal.h>
    #include "struct.h"
    #define TRUE 1
    #define FALSE 0

extern int global;

int navy(int argc, char **argv, navy_t *boat);
int help(void);
int my_put_nbr(int nb);
void my_putchar(char c);
int player_one(navy_t *boat);
int player_two(int ac, char **av, navy_t *boat);
int my_getnbr(char const *str);
void empty_maps(navy_t *boat);
int my_putstr(char const *str);
void display_mmap(navy_t *boat);
void display_emaps(navy_t *boat);
void my_putchar(char c);
void enemy_map(navy_t *boat);
void my_map(navy_t *boat);
int par_fil(char *argv, navy_t *boat);
char **str_to_word_array(char *buf, char cut);
int parseur(char *ligne, navy_t *boat);
void hor_pos(int min, int max, int hor, navy_t *boat);
void hor_boat(int hor, char s, char e, navy_t *boat);
int is_horizontal(char s, char e);
void ver_pos(int min, int max, int ver, navy_t *boat);
int is_vertical(char s, char e);
void ver_boat(int ver, char s, char e, navy_t *boat);
void fill_map(navy_t *boat, char *start, char *end);
int game_loop(navy_t *boat);
void convsendsig(int pid, char *coordonnees);
void signalhandler(int signalNum, navy_t *boat);
void get_sig(int signum, siginfo_t *info, void *context);
void send_attack(int x, int y, navy_t *boat);
int my_attack(navy_t *boat);
int my_defense(navy_t *boat);
int hit_or_not(navy_t *boat);
void hit(navy_t *boat);
void missed(navy_t *boat);
int my_strlen(char const *str);

#endif /* !MY_H_ */
