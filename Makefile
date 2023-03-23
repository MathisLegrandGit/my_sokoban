##
## EPITECH PROJECT, 2021
## Root Makefile
## File description:
## Root Makefile
##

SRC	=	my_sokoban.c	\
		error.c    \
		array_calc.c    \
		move_char.c    \
		move_char2.c    \
		coord_finders.c    \

OBJ	=	$(SRC:.c=.o)

LIB	=	-L ./lib

NAME	=	my_sokoban

MY	=	my.h

INCLUDE	=	-I./include

CFLAGS = -g3

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -g3 $(INCLUDE) $(LIB) -lmy -g -lncurses

clean:
		rm -f $(OBJ)
		rm -f *~

fclean:	clean
		rm -f $(NAME)
		make fclean -C lib/my

re:	fclean all
