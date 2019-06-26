##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile the Snake game to shared library into the games directory
##

LIB_SO_NAME	=	../../../games/lib_arcade_nibbler.so

SNAKE_SRC	=	Snake.cpp

SNAKE_OBJ	=	$(SNAKE_SRC:.cpp=.o)

CC	=	g++ -g

CFLAGS	=	-Wall -Wextra -Werror -I../../../include -I../../../include/games/Snake -fPIC -shared

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(LIB_SO_NAME)

$(LIB_SO_NAME): $(SNAKE_OBJ)
	@$(CC) $(SNAKE_OBJ) $(CFLAGS) -o $(LIB_SO_NAME)

clean:
	rm -f $(SNAKE_OBJ)

fclean: clean
	rm -f $(LIB_SO_NAME)

re: fclean all