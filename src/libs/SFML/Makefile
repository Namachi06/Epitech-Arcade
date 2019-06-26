##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile SFML to shared library file into ./lib directory
##

LIB_SO_NAME	=	../../../lib/lib_arcade_sfml.so

SFML_SRC	=	SFML.cpp

SFML_OBJ	=	$(SFML_SRC:.cpp=.o)

CC	=	g++ -g

SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

CFLAGS	=	-Wall -Wextra -Werror -I../../../include/libs/SFML $(SFMLFLAGS) -fPIC -shared

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(LIB_SO_NAME)

$(LIB_SO_NAME): $(SFML_OBJ)
	@$(CC) $(SFML_OBJ) $(CFLAGS) -o $(LIB_SO_NAME)

clean:
	@rm -f $(SFML_OBJ)

fclean: clean
	@rm -f $(LIB_SO_NAME)

re: fclean all