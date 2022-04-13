##
## EPITECH PROJECT, 2021
## MY_HUNTER
## File description:
## It's the Makefile of my_hunter project
##

LIB	=	lib/my_strlen.c      \
		lib/my_getnbr.c	\
		lib/my_atoi.c	\
		lib/my_putchar.c     \
		lib/my_put_nbr.c     \
		lib/my_putstr.c      \
		lib/my_strcmp.c      \
		lib/my_strncat.c     \
		lib/my_strncpy.c     \
		lib/my_printf.c	\
		lib/new_put_nbr.c	\
		lib/str_to_array.c	\
		lib/my_str_to_word_array.c

SRC = 	src/*.c

NAME = ai

all:
	@echo ">>> Librairy compiled."
	@gcc ${SRC} ${LIB} -o ${NAME} -g3 -L.
	@echo ">>> Executable \"${NAME}\" created."

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@rm -f libmy.a
	@echo ">>> All files was clean."

re:	fclean all

