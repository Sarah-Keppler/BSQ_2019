/*
** EPITECH PROJECT, 2019
** Bsq
** File description:
** Find the bigger, greater and the more beautiful square.
*/

#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

void display_square(char *buff, square_s *biggest, int len_line)
{
    for (int i = 0; biggest->size > i; ++i)
        for (int y = 0; biggest->size > y; ++y)
            buff[biggest->pos + i + y * (len_line + 1)] = 'x';
    my_putstr(buff);
    my_putchar('\n');
}

void *find_square(char *buff, int limit, int len_line)
{
    square_s current;
    square_s biggest;
    int size = 0;

    biggest.size = 0;
    for (int i = 0; limit > i; ++i) {
        if ('.' == buff[i]) {
            size = get_size(buff, i, len_line);
            current.size = size;
            current.pos = i;
            replace_square(&current, &biggest);
        } else {
            current.size = size;
            current.pos = i;
            replace_square(&current, &biggest);
        }
    }
    display_square(buff, &biggest, len_line);
}

char *read_map(char **av, int *len)
{
    int fd = open(av[1], O_RDONLY);
    char *buffer;
    struct stat stats;

    if (-1 == fd) {
        my_putstr("The file didn't open ~ Error\n");
        return (NULL);
    }
    if (0 == stat(av[1], &stats)) {
        buffer = malloc(sizeof(char) * (stats.st_size + 1));
        if (NULL == buffer)
            return (NULL);
        read(fd, buffer, stats.st_size);
    } else
        return (NULL);
    buffer[stats.st_size] = '\0';
    *len = stats.st_size;
    close(fd);
    return (buffer);
}

int main(int ac, char **av)
{
    char *map;
    int len = 0;
    int len_line = 0;
    int go_next_line = 0;

    if (ac != 2) {
        my_putstr("Too less argument ~ Error\n");
        return (84);
    }
    map = read_map(av, &len);
    if (NULL == map || false == check_fst_line(map))
        return (84);
    len_line = get_length_line(map, &go_next_line);
    if (84 == len_line)
        return (84);
    find_square(map + go_next_line + 1, len, len_line);
    free(map);
    return (0);
}
