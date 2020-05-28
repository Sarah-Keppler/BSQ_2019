##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make a lib and a binary mode of a cube ! Then a cube^2 !
##

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	+=	-Wall -Wextra -g

LDFLAGS =	-Llib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all
	make -C lib/my re
