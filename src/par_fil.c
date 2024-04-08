/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-pierre-louis.schorsch
** File description:
** par_fil
*/

#include "../include/my.h"

int is_line_right(char *str)
{
    if (str[0] < '2' || str[0] > '5')
        return (84);
    if (str[1] != ':' || str[4] != ':')
        return (84);
    if (str[2] < 'A' || str[2] > 'H')
        return (84);
    if (str[3] < '1' || str[3] > '8')
        return (84);
    if (str[5] < 'A' || str[5] > 'H')
        return (84);
    if (str[6] < '1' || str[6] > '8')
        return (84);
    if (str[7] != '\n' && str[7] != '\0')
        return (84);
}

int reading(FILE *file, navy_t *boat)
{
    char *ligne = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    int ret_val = 2;

    read = getline(&ligne, &len, file);
    while (read != - 1) {
        if (is_line_right(ligne) == 84)
            return (84);
        ret_val = parseur(ligne, boat);
        read = getline(&ligne, &len, file);
        if (ret_val == 1)
            return 84;
        i++;
    }
    if (i != 4)
        return 84;
}

int par_fil(char *argv, navy_t *boat)
{
    FILE *file = fopen(argv, "r");

    if (file == NULL)
        return (84);
    if (reading(file, boat) == 84)
        return (84);
    fclose(file);
    return 0;
}
