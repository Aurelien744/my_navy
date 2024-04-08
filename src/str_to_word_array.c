/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Day08
*/

#include "../include/my.h"

static int count_space(char *str, char cut)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == cut)
            count++;
    }
    return (count + 1);
}

static int find_max_size(char *str, char cut)
{
    int max_size = 0;
    int temp_size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == cut) {
            max_size = (temp_size > max_size) ? temp_size : max_size;
            temp_size = 0;
        } else {
            temp_size++;
        }
    }
    max_size = (temp_size > max_size) ? temp_size : max_size;
    return (max_size);
}

static char **finalize_array(char **tab, int last_word_len, int word_count)
{
    tab[word_count - 1][last_word_len] = '\0';
    tab[word_count] = NULL;
    return tab;
}

static void fill_array(char **tab, char *buf, char cut)
{
    int i = 0;
    int j = 0;

    for (int a = 0; buf[a] != '\0'; a++) {
        if (buf[a] == cut) {
            tab[j][i] = '\0';
            i = 0;
            j++;
        } else {
            tab[j][i] = buf[a];
            i++;
        }
    }
    finalize_array(tab, i, j + 1);
}

char **str_to_word_array(char *buf, char cut)
{
    int space = count_space(buf, cut);
    int max_size = find_max_size(buf, cut);
    char **tab = malloc(sizeof(char *) * (space + 1));

    if (!tab)
        return (NULL);
    for (int i = 0; i < space; i++) {
        tab[i] = malloc(sizeof(char) * (max_size + 1));
    }
    fill_array(tab, buf, cut);
    return (tab);
}
