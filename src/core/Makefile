##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile core
##

SRC_proj	=	main.cpp \
				Core.cpp \
				File.cpp \
				../exception/ArcadeExceptions.cpp \

OBJ		=	$(SRC_proj:.cpp=.o)

CFLAGS	=	-W -Wall -Wextra -g -ldl -fPIC

INCLUDES	=	-I../../include/core -I../../include/exception -I../../include/games -I../../include/libs

NAME	=	../../arcade

%.o: %.cpp
	g++ -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	@g++ $(OBJ) $(CFLAGS) $(INCLUDES) -o $(NAME)

clean:
	rm -f $(OBJ) *.gcno *.gcda

fclean: clean
	rm -f $(NAME)