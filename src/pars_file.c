/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-pierre-louis.schorsch
** File description:
** pars_file
*/

#include "../include/my.h"

static int taillesVerifiees[4] = {FALSE, FALSE, FALSE, FALSE};

int difflettre(int diff_let, int let_end, int let_beg)
{
    if (let_beg > let_end) {
        diff_let = let_beg - let_end;
    } else {
        diff_let = let_end - let_beg;
    }
    return diff_let;
}

int diffnum(int diff_num, int num_beg, int num_end)
{
    if (num_beg > num_end) {
        diff_num = num_beg - num_end;
    } else {
        diff_num = num_end - num_beg;
    }
    return diff_num;
}

int val_coo(char *debut, char *fin, int taille)
{
    int let_beg = debut[0];
    int num_beg = debut[1] - '0';
    int let_end = fin[0];
    int num_end = fin[1] - '0';
    int diff_num = 0;
    int diff_let = 0;

    if (let_beg < 'A' || let_beg > 'H' || let_end < 'A' ||
        let_end > 'H' || num_beg < 1 || num_beg > 8 ||
        num_end < 1 || num_end > 8) {
        return 0;
    }
    diff_num = diffnum(diff_num, num_beg, num_end);
    diff_let = difflettre(diff_let, let_end, let_beg);
    if ((let_beg == let_end && diff_num == taille - 1) ||
        (num_beg == num_end && diff_let == taille - 1)) {
        return 0;
    } else {
        return 1;
    }
}

int taillevalide(int taille)
{
    int index = taille - 2;

    if (taille < 2 || taille > 5) {
        return 1;
    }
    if (taillesVerifiees[index] == TRUE) {
        return 2;
    }
    taillesVerifiees[index] = TRUE;
    return 0;
}

int parseur(char *ligne, navy_t *boat)
{
    char **elements = str_to_word_array(ligne, ':');
    int taille = my_getnbr(elements[0]);
    char *coordDebut = elements[1];
    char *coordFin = elements[2];
    int re = taillevalide(taille);
    int ret = val_coo(coordDebut, coordFin, taille);

    boat->size = taille + 48;
    if (re == 0 && ret == 0) {
        fill_map(boat, coordDebut, coordFin);
        return 0;
    } else {
        return 1;
    }
    for (int i = 0; elements[i] != NULL; i++) {
        free(elements[i]);
    }
    free(elements);
}
