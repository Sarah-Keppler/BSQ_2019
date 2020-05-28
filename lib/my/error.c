/*
** EPITECH PROJECT, 2019
** error
** File description:
** Allow you to have 2.5 % ! YEAH !!!
*/

#include <stdbool.h>
#include <unistd.h>
#include "my.h"

_Bool check_fst_line(char *buff)
{
    for (int i = 0; '\n' != buff[i]; ++i) {
        if (!('0' <= buff[0] && '9' >= buff[0])) {
            write(2, "Error 1.0", 9);
            return (false);
        }
    }
    return (true);
}

int get_line_len(char *map, int i)
{
    int nb = 0;
    
    for (; '\n' != map[i]; ++i) {
        ++nb;
    }
    return (nb);
}

_Bool check_every_line(char *map, int len_line)
{
    int nb_per_line = get_line_len(map, 0);
    
    if (nb_per_line != len_line) {
        my_putstr("Size differs !\n");
        return (false);
    }
    for (int i = 0; map[i]; ++i) {
        if ('\n' == map[i]) {
            nb_per_line = get_line_len(map, i + 1);
        }
        if (nb_per_line != len_line) {
            my_putstr("Size differs !\n");
            return (false);
        }
    }
    return (true);
}

_Bool check_size(char *map, int len_line)
{
    int nb_n = 0;

    for (int i = 0; map[i]; ++i) {
        if ('\n' == map[i] || '\0' == map[i - 1])
            ++nb_n;
    }
    if (nb_n != len_line) {
        my_putstr("Size differs !\n");
        return (false);
    }
    if (false == check_every_line(map, len_line))
        return (false);
    return (true);
}
