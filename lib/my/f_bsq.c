/*
** EPITECH PROJECT, 2019
** f_bsq
** File description:
** Some useful functions for bsq.
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

int increase(char *buff, int pos, int len_line, int size)
{
    for (int i = 0; size > i; ++i)
        for (int y = 0; size > y; ++y)
            if (buff[pos + i + y * (len_line + 1)] != '.')
                return (0);
    return (1);
}

void replace_square(square_s *current, square_s *biggest)
{
    if (current->size > biggest->size)  {
        biggest->size = current->size;
        biggest->pos = current->pos;
    }
}

int get_size(char *buff, int pos, int len_line)
{
    int size = 0;

    while (1 == increase(buff, pos, len_line, size + 1)) {
        ++size;
    }
    return (size);
}

int get_length_line(char *map, int *go_next_line)
{
    int nb = 0;
    char *number;

    for (int i = 0; '\n' != map[i]; ++i) {
        *go_next_line += 1;
    }
    number = malloc(sizeof(char) * (*(go_next_line) + 1));
    if (NULL == number)
        return (84);
    for (int i = 0; *(go_next_line) > i; ++i) {
        number[i] = map[i];
    }
    number[*(go_next_line)] = '\0';
    nb = my_getnbr(number);
    free(number);
    return (nb);
}
