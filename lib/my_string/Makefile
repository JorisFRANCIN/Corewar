##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile the lib
##

SRC	=	my_strcmp.c	\
		my_strncmp.c	\
		my_strlen.c	\
		my_strcpy.c	\
		my_strcat.c	\
		my_strdup.c	\
		my_str_to_word_array.c	\
		my_memset.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_string.a

NAME_H	=	my_string.h

CFLAGS	=	-W -Wextra -Wall -g3

all:	$(NAME)

$(NAME): fclean $(OBJ)
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
