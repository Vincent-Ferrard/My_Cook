##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## My_Cook
##

SRC	=	src/all_actions.c	\
		src/clock.c		\
		src/display.c		\
		src/destroy.c		\
		src/file.c		\
		src/info.c		\
		src/info2.c		\
		src/init.c		\
		src/init2.c		\
		src/main.c		\
		src/mouse.c		\
		src/recipe.c		\
		src/recipe2.c		\
		src/recipe3.c		\
		src/utils.c		\
		src/utils2.c		\
		src/utils3.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_cook

CFLAGS	=	-W -Wall -Wextra -Iinc

LDFLAGS	=	-l c_graph_prog 

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
