##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	*.c	\

NAME	=	fs_open_file

OBJ	=	libmy.a

all	:	$(OBJ)

$(OBJ)	:
	gcc -c lib/my/$(SRC)
	ar rc $(OBJ) *.o
	gcc -o $(NAME) -g3 main.c -L. -lmy -I include

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
