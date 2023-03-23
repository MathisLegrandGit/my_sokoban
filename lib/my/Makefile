##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task01
##

SRC	=		my_strncpy.c     \
		my_putchar.c     \
		my_put_nbr.c     \
		my_revstr.c     \
		my_putstr.c     \
		my_strlen.c     \
		my_printf.c    \
		my_concat_strings.c    \
		my_strdup.c    \
		my_strcmp.c    \
		my_strcpy.c    \
		my_str_to_word_array.c    \

OBJ  = $(SRC:.c=.o)

NAME = libmy.a

MY = my.h

DIRECTORY = ../../include

CFLAGS = -g3

all: $(NAME)

$(NAME):		$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../$(NAME)

re:	fclean all
