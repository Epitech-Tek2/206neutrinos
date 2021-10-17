##
## EPITECH PROJECT, 2021
## B-MAT-400-STG-4-1-206neutrinos-clement.muth [WSL: Ubuntu]
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	sources/main.c

NAME	=	206neutrinos

CFLAGS	=	-I./includes -g

LDFLAGS += -lm

LBLIBS	=	-L./bin/ -lstring -L./bin/ -lutils -L./bin/ -lassert
LIB_PATH	=	library

OBJS	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LBLIBS) $(LDFLAGS)

tests_run: all
	gcc bonus/*.c tests/*.c -o unit_tests --coverage -lcriterion $(CFLAGS) $(LBLIBS) $(LDFLAGS)
	- ./unit_tests

lib:
	$(MAKE) -C $(LIB_PATH)/string/
	$(MAKE) -C $(LIB_PATH)/assert/
	$(MAKE) -C $(LIB_PATH)/utils/

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIB_PATH)/string/ clean
	$(MAKE) -C $(LIB_PATH)/assert/ clean
	$(MAKE) -C $(LIB_PATH)/utils/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_PATH)/string/ fclean
	$(MAKE) -C $(LIB_PATH)/assert/ fclean
	$(MAKE) -C $(LIB_PATH)/utils/ fclean

re: fclean all

.PHONY: all clean fclean re