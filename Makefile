##
## EPITECH PROJECT, 2017
## NWP_myarpspoof_2018
## File description:
## Makefile
##

.PHONY: clean fclean re

NAME	=	myARPspoof

CFLAGS	+= -I ./includes/

SRCS	=	./src/main.c	\
			./src/error.c	\
			./src/check_args.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
		rm $(OBJS)

tests_run: $(SRCS_TEST)
	$(CC) $(SRCS_TEST) $(SRCS) -I./includes -o units --coverage -lcriterion
	./units

wc:
	wc $(SRCS) ./includes/*

ta:
	make re
	./bonus/test_auto.sh
	make fclean

clean:
	$(RM) $(OBJS) *.g*

fclean: clean
	$(RM) $(NAME) units

re: fclean all

print_tests:
	lcov --directory ./ -c -o rapport.info
	genhtml -o ./report -t "code coverage report" rapport.info
	xdg-open ./report/index.html &>/dev/null
