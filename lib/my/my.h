/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Header for ping pong ! Ping.. Pong.. ping .. pong
*/

#ifndef MY_H_
#define MY_H_

//struct bsq
typedef struct square_t {
    int pos;
    int size;
} square_s;

//Display
void my_putchar(char);
int my_putstr(char const *);
int my_put_nbr(int);
int display_digits(int);

//String
int my_strlen(char const *);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int match(char *, char const *, int);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);

//Calculation
int my_compute_power_rec(int, int);

//Others functions
int my_getnbr(char const *);
int my_str_character(char const *);
int my_strlen_per(char const *, char);
int my_isneg(int);
void my_swap(int *, int *);
void my_swap_char(char *, char *);

//bsq
int increase(char *, int, int, int);
void replace_square(square_s *, square_s *);
int get_size(char *, int, int);
int get_length_line(char *, int *);
_Bool check_fst_line(char *);
_Bool check_every_line(char *, int);
_Bool check_size(char *, int);
int get_line_len(char *, int);
#endif /* MY_H_ */
