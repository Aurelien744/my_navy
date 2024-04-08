/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** navy
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct navy_s {
    pid_t my_pid;
    pid_t enemy_pid;
    char **my_map;
    char **enemy_map;
    char *coord;
    char size;
    int boule;
}navy_t;

#endif
