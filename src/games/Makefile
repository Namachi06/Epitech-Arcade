##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile all games to shared library into the games directory
##

all:
	rm -rf ../../games/
	mkdir ../../games/
	@make -s -C Pacman
	@make -s -C Snake

clean:
	@make clean -s -C Pacman
	@make clean -s -C Snake

fclean: clean
	@make fclean -s -C Pacman
	@make fclean -s -C Snake

re: fclean all