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
			src/utils/param.c	\
			src/instructions/add.c	\
			src/instructions/aff.c	\
			src/instructions/and.c	\
			src/instructions/fork.c	\
			src/instructions/ld.c	\
			src/instructions/ldi.c	\
			src/instructions/live.c	\
			src/instructions/lld.c	\
			src/instructions/lldi.c	\
			src/instructions/or.c	\
			src/instructions/st.c	\
			src/instructions/sti.c	\
			src/instructions/sub.c	\
			src/instructions/xor.c	\
			src/instructions/zjmp.c	\
			src/instructions/lfork.c	\
			src/place_champion_in_arena.c	\
			src/champions.c	\
			src/op.c	\
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
