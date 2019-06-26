##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile Ncurse to shared library file into ./lib directory
##

LIB_SO_NAME	=	../../../lib/lib_arcade_ncurses.so

NCURSES_SRC	=	Ncurses.cpp \
				NcursesFunc.cpp

NCURSES_OBJ	=	$(NCURSES_SRC:.cpp=.o)

CC	=	g++ -g

CFLAGS	=	-Wall -Wextra -Werror -I../../../include/libs/Ncurses -lncurses -fPIC -shared

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(LIB_SO_NAME)

$(LIB_SO_NAME): $(NCURSES_OBJ)
	@$(CC) $(NCURSES_OBJ) $(CFLAGS) -o $(LIB_SO_NAME)

clean:
	rm -f $(NCURSES_OBJ)

fclean: clean
	rm -f $(LIB_SO_NAME)

re: fclean all