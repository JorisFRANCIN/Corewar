##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile the lib
##

SRC	=	my_put_nbr.c	\
		my_put_unsigned_nbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_putstr_octal.c	\
		my_put_nbr_base.c	\
		my_put_nbr_binary.c	\
		my_put_nbr_hex.c	\
		my_printf.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_stdio.a

NAME_H	=	my_stdio.h

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
