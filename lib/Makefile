##
## EPITECH PROJECT, 2022
## make
## File description:
## make corewar
##

all:
	$(MAKE) -C my_string
	$(MAKE) -C my_stdlib
	$(MAKE) -C my_stdio

clean:
	make clean -C my_stdlib
	make clean -C my_string
	make clean -C my_stdio

fclean: clean
	make fclean -C my_stdlib
	make fclean -C my_string
	make fclean -C my_stdio

my_clean: fclean
	make my_clean -C my_stdlib
	make my_clean -C my_string
	make my_clean -C my_stdio

re: fclean all
	make re -C my_stdlib
	make re -C my_string
	make re -C my_stdio

my_re: my_clean all
	make my_re -C my_stdlib
	make my_re -C my_string
	make my_re -C my_stdio

.PHONY: all clean fclean my_clean re my_re
