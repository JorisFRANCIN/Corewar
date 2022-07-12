##
## EPITECH PROJECT, 2022
## make
## File description:
## make corewar
##

NAME	=	asm

SRC_DIR	=	src/

INIT_DIR	=	 $(SRC_DIR)init/

ERROR_HANDLING	=	$(SRC_DIR)error_handling/

BYTECODE_DIR	=	$(SRC_DIR)bytecode/

WRITE_INSTRUCTIONS	=	$(BYTECODE_DIR)write_cases/

WRITE_SRC	=	$(WRITE_INSTRUCTIONS)live_case.c	\
			$(WRITE_INSTRUCTIONS)ld_case.c	\
			$(WRITE_INSTRUCTIONS)st_case.c	\
			$(WRITE_INSTRUCTIONS)add_case.c	\
			$(WRITE_INSTRUCTIONS)sub_case.c	\
			$(WRITE_INSTRUCTIONS)and_case.c	\
			$(WRITE_INSTRUCTIONS)or_case.c	\
			$(WRITE_INSTRUCTIONS)xor_case.c	\
			$(WRITE_INSTRUCTIONS)zjmp_case.c	\
			$(WRITE_INSTRUCTIONS)ldi_case.c	\
			$(WRITE_INSTRUCTIONS)sti_case.c	\
			$(WRITE_INSTRUCTIONS)fork_case.c	\
			$(WRITE_INSTRUCTIONS)lld_case.c	\
			$(WRITE_INSTRUCTIONS)lldi_case.c	\
			$(WRITE_INSTRUCTIONS)lfork_case.c	\
			$(WRITE_INSTRUCTIONS)aff_case.c	\

EXTERN_SRC	=	../op.c	\
			../type_verificator.c	\
			../type_verificator_advance.c	\

SRC	=	$(SRC_DIR)assembler.c	\
		$(INIT_DIR)init_content.c	\
		$(ERROR_HANDLING)valid_header.c	\
		$(ERROR_HANDLING)file_verification.c	\
		$(ERROR_HANDLING)valid_instruction.c	\
		$(ERROR_HANDLING)my_verify_content.c	\
		$(ERROR_HANDLING)find_word_in_str.c	\
		$(ERROR_HANDLING)count_arg.c	\
		$(BYTECODE_DIR)file_to_bytecode.c	\
		$(BYTECODE_DIR)fill_instructions.c	\
		$(BYTECODE_DIR)into_coding_byte.c	\
		$(BYTECODE_DIR)indexes_handler.c	\
		$(BYTECODE_DIR)my_hex_count.c	\
		$(BYTECODE_DIR)browse_labels.c	\
		$(BYTECODE_DIR)my_strfill.c	\
		$(SRC_DIR)free_array.c	\
		$(SRC_DIR)free_linked_list.c	\
		$(WRITE_SRC)	\
		$(EXTERN_SRC)

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-I./../include

LDFLAGS	=	-L ./../lib/ -lmy_stdio -lmy_stdlib -lmy_string

CFLAGS	=	-W -Wall -Wextra -g3

$(MAKE): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

all: $(MAKE)

clean:
	$(RM) $(SRC_DIR)*.o
	$(RM) $(INIT_DIR)*.o
	$(RM) $(ERROR_HANDLING)*.o
	$(RM) $(BYTECODE_DIR)*.o
	$(RM) $(WRITE_INSTRUCTIONS)*.o
	$(RM) ../$(SRC_DIR)*.o

fclean: clean
	$(RM) $(NAME)

my_clean: fclean
	@$(RM) *~
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) *#
	@$(RM) include/*~
	@$(RM) $(SRC_DIR)/*~
	@$(RM) tests/*~
	@$(RM) vgcore*

val_debug: my_clean $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)

re: fclean all

my_re: my_clean re

.PHONY: all clean fclean my_clean re my_re
