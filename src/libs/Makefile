##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile all graphics to shared library, put into ./lib
##

all:
	rm -rf ../../lib/
	mkdir ../../lib/
	@make -s -C Ncurses
	@make -s -C SFML

clean:
	@make clean -s -C Ncurses
	@make clean -s -C SFML

fclean: clean
	@make fclean -s -C Ncurses
	@make fclean -s -C SFML

re: fclean all