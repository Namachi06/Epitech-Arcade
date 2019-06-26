##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Core Makefile: Compile all project
##

all:
	@make -s -C src

core:
	@make core -s -C src

games:
	@make games -s -C src

graphicals:
	@make graphicals -s -C src

clean:
	@make clean -s -C src

fclean: clean
	@make fclean -s -C src

re: fclean all

.PHONY:	all core games graphicals clean fclean re