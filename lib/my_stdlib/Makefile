##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile the lib
##

SRC	=	my_atoi.c	\
		my_getnbr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_stdlib.a

NAME_H	=	my_stdlib.h

CFLAGS	=	-W -Wall -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp  $(NAME_H) ../../include/
	cp $(NAME) ../

clean:
	$(RM) $(OBJ)

my_clean:
	$(RM) *~
	$(RM) *#
	$(RM) *.#

fclean: clean
	$(RM) $(NAME)
	$(RM) ../../include/$(NAME_H)
	$(RM) ../$(NAME)

val_debug: fclean $(OBJ)
	ar rc $(NAME) $(OBJ) $(CFLAGS)
	cp  $(NAME_H) ../../include/
	cp $(NAME) ../

re:	fclean all
