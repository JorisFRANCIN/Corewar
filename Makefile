##
## EPITECH PROJECT, 2022
## make
## File description:
## make corewar
##

$(MAKE):
	make -C lib/
	make -C asm/
	make -C corewar/

all: $(MAKE)

clean:
	@make clean -C lib/
	make clean -C asm/
	make clean -C	corewar/
	$(RM) *.o

fclean: clean
	@make fclean -C lib/
	make fclean -C asm/
	make fclean -C corewar/

my_clean: fclean
	@make my_clean -C lib/
	make my_clean -C asm/
	@$(RM) *~
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) *#
	@$(RM) include/*~
	@$(RM) src/*~
	@$(RM) tests/*~
	@$(RM) vgcore*

val_debug: my_clean
	make -C lib
	make val_debug -C asm

re: fclean all

my_re: my_clean re

.PHONY: all clean fclean my_clean re my_re
