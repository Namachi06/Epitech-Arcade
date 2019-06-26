##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile the Pacman game to shared library into the games directory
##

LIB_SO_NAME	=	../../../games/lib_arcade_pacman.so

PACMAN_SRC	=	Pacman.cpp

PACMAN_OBJ	=	$(PACMAN_SRC:.cpp=.o)

CC	=	g++

CFLAGS	=	-Wall -Wextra -Werror -I../../../include -I../../../include/games/Pacman -fPIC -shared

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(LIB_SO_NAME)

$(LIB_SO_NAME): $(PACMAN_OBJ)
	@$(CC) $(PACMAN_OBJ) $(CFLAGS) -o $(LIB_SO_NAME)

clean:
	rm -f $(PACMAN_OBJ)

fclean: clean
	rm -f $(LIB_SO_NAME)

re: fclean all