##
## EPITECH PROJECT, 2022
## make
## File description:
## make rules
##

NAME	=	corewar

CC		= gcc

RM		= rm -f

ASM_FUNC = $(addprefix src/asm_func/, \
			add.c \
			aff.c \
			and.c \
			fork.c \
			ld.c \
			ldi.c \
			lfork.c \
			live.c \
			lld.c \
			lldi.c \
			or.c \
			st.c \
			sti.c \
			sub.c \
			xor.c \
			zjmp.c \
)

SRC	=	src/vm.c \
		src/utils.c \
		src/my_strcmp.c \
		src/my_strlen.c \
		src/my_atoi.c \
		src/my_str_to_word_array.c \
		src/my_verify_nbr.c \
		src/loop.c \
		src/arena.c \
		../op.c \

OBJ		= $(SRC:.c=.o)

ASM_OBJ	= $(ASM_FUNC:.c=.o)

CPPFLAGS = -iquote./include/

LDFLAGS	=	-L ./../lib/ -lmy_stdio -lmy_stdlib -lmy_string

all: $(NAME)

$(NAME):	$(OBJ) $(ASM_OBJ)
	$(CC) $(OBJ) $(ASM_OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS)

clean:
	@$(RM) $(OBJ) $(ASM_OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re