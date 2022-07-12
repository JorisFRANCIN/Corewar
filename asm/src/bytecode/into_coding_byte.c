/*
** EPITECH PROJECT, 2022
** into_coding_byte
** File description:
** put the binary in coding byte
*/

#include "corewar.h"

int my_compute_power_rec(int nb, int p)
{
    int result;

    result = nb;
    if (p == 0)
        result = 1;
    if (nb == 0 || p < 0)
        result = 0;
    if (nb == 0 && p == 0)
        result = 1;
    if (p == 1 && nb > 0)
        result = nb;
    if (p > 1) {
        p--;
        result = result * my_compute_power_rec(nb, p);
    }
    return (result);
}

int into_decimal(int nbr)
{
    int new_nbr = 0;
    int remain = 0;

    for (int i = 0; nbr != 0; i++) {
        remain = nbr % 10;
        nbr /= 10;
        new_nbr += remain * my_compute_power_rec(2, i);
    }
    return new_nbr;
}

int into_coding_byte(int *tab)
{
    int coding_byte = 0;
    int index = 6;
    int mult = 0;

    for (int i = 0; i != 4; i++, index -= 2) {
        mult = my_compute_power_rec(10, index);
        if (tab[i] == 1)
            coding_byte += 1 * mult;
        if (tab[i] == 2)
            coding_byte += 10 * mult;
        if (tab[i] == 4)
            coding_byte += 11 * mult;
    }
    coding_byte = into_decimal(coding_byte);
    return coding_byte;
}
