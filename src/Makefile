##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile source files
##

all:
	@make -s -C core
	@make -s -C libs
	@make -s -C games

core:
	@make -s -C core

games:
	@make -s -C games

graphicals:
	@make -s -C libs

clean:
	@make clean -s -C core
	@make clean -s -C libs
	@make clean -s -C games

fclean: clean
	@make fclean -s -C core
	@make fclean -s -C libs
	@make fclean -s -C games

re: fclean all

.PHONY:	all core games graphicals clean fclean re
