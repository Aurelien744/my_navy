/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Day03
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void print_while(long memo, int num)
{
    memo = memo / 10;
    while (memo != 1) {
        num = memo % 10;
        memo = memo / 10;
        my_putchar(num + 48);
    }
}

int my_put_nbr(int nb)
{
    int num = 0;
    long memo = 0;
    long ara = nb;

    if (ara < 0) {
        my_putchar('-');
        ara = ara * (-1);
    }
    if (ara == 0) {
        my_putchar('0');
        return (0);
    }
    ara = ara * 10 + 1;
    while (ara != 0) {
        num = ara % 10;
        memo = (memo + num) * 10;
        ara = ara / 10;
    }
    print_while(memo, num);
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++);
    return (i);
}
