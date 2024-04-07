##
## EPITECH PROJECT, 2023
## my_paint
## File description:
## Makefile for my_paint
##

CFLAGS	= -W -Wall -Wextra -ggdb3

CPPFLAGS = -I include/ -L./ -lmy

GRAPHICS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

MAIN =	src/main.c

SRC =	src/errors.c	\
		src/init.c	\
		src/tools.c	\
		src/display.c	\
		src/tool_menu.c	\
		src/file_menu.c	\
		src/help_window.c

UNITS = --coverage -lcriterion

OBJ = ${SRC:.c=.o} ${MAIN:.c=.o}

TEST_SRC = 	$(SRC)

TEST_OBJ = ${TEST_SRC:.c=.o}

NAME = my_paint

all: buildlib $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(GRAPHICS)

buildlib:
	make -C./lib/my -s

clean:
	make -C./lib/my -s clean
	@rm -f $(OBJ)
	@rm -f $(TEST_OBJ)
	@find . -name "*.gcda" -delete -o -name "*.gcno" -delete

fclean:	clean
	make -C./lib/my -s fclean
	@rm -f $(NAME)
	@rm -f unit_tests

re: fclean all

unit_tests:	CFLAGS += -lcriterion --coverage -g3
unit_tests:	fclean $(TEST_OBJ)
			$(CC) $(TEST_OBJ) $(CFLAGS) -o unit_tests

tests_run:	unit_tests
	@./unit_tests
	@gcovr --exclude tests/ --exclude main.c
	@gcovr --exclude tests/ --exclude main.c --branches

.PHONY:	all clean fclean re unit_tests tests_run
