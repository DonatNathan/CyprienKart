##
## EPITECH PROJECT, 2021
## MY_HUNTER
## File description:
## It's the Makefile of my_hunter project
##

LIB	=	lib/my_strlen.c      \
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

SRC = 	src/*.c

OBJ = $(LIB:.c=.o)

NAME = ai

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc libmy.a $(OBJ)
	@echo ">>> Librairy compiled."
	@gcc -g3 -o ${NAME} $(SRC) -L. libmy.a
	@echo ">>> Executable \"${NAME}\" created."

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f libmy.a
	@echo ">>> All files was clean."

re: fclean all
