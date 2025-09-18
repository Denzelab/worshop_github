##
## EPITECH PROJECT, 2025
## makefile
## File description:
## Makefile
##

SRC		=	src/main.c	\
			src/parser/parsing.c	\
			src/utils/usage.c	\
			src/utils/valid_number.c	\
			src/utils/my_strcmp.c	\
			src/utils/my_strlen.c	\
			src/utils/my_getnbr.c	\
			src/utils/my_strdup.c	\
			src/champions.c	\
			src/arena.c	\
			src/loader.c	\
			src/vm.c	\
			src/dump_arena.c	\
			src/init_arena.c	\
			src/place_champion.c	\
			src/init_processes.c	\
			src/utils/mini_printf.c

NAME	=	corewar

SR	=	tests/t.c

all:	$(NAME)

$(NAME):	$(SRC)
	@gcc -o $(NAME) $(SRC) -g3

unit_tests: fclean $(NAME)

	@gcc -o unit_tests $(SR) src/utils/valid_number.c -coverage -lcriterion

tests_run:	unit_tests
	./unit_tests

clean:
	@rm -rf *.log
	@rm -f *~
	@rm -f *#
	@rm -f *gcno
	@rm -f *gcda

fclean:	clean
	@rm -f $(NAME)
	@rm -f B-CPE-200_op/*~
	@rm -f coding-style-reports.log
	@rm -f unit_tests

re:	fclean all
