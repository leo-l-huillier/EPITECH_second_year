##
## EPITECH PROJECT, 2022
## assembleur
## File description:
## Makefile
##

LIB			=	libasm.so

SRC			=	lib_asm/strstr.asm	\
				lib_asm/strlen.asm	\
				lib_asm/strcmp.asm	\
				lib_asm/memset.asm	\
				lib_asm/memcpy.asm	\
				lib_asm/memmove.asm	\


SRC_TEST	=	Tests/test_strchr.c	\
				Tests/test_strlen.c	\

MAIN		=	main.c

OBJ			=	$(SRC:.asm=.o)

OBJ_TST		=	$(SRC_TST:.asm=.o)

ASM			=	nasm

CC			=	gcc

RM			=	rm -f

CFLAGS		+=	-fpic -shared

CPPFLAGS	+=	-I./include

LDFLAGS		=	-f elf64

TESTFLAGS	=	-lcriterion --coverage -L -lasm -ldl

NAME_LIB	=	libmy.a

NAME_TEST	=	unit_tests

NAME		=	libasm.so

all: 		$(NAME)

%.o: %.asm
			$(ASM) $(LDFLAGS) $< -o $@

$(NAME):	$(OBJ)
			ld $(CFLAGS) $(OBJ) -o $(NAME)

debug:		CFLAGS += -g3
debug:		re

clean:
			@$(RM) $(OBJ)
			@$(RM) $(LIB) $(NAME_TEST) *.gcno *.gcda vgcore* a.out

fclean:		clean
			@$(RM) $(NAME) $(NAME_LIB)

test:		re
			@gcc -fno-builtin $(MAIN)
			@LD_PRELOAD=./$(NAME) ./a.out

re:			fclean all

tests_run:	re
			$(CC) -o unit_tests $(SRC_TEST) $(TESTFLAGS) -g3
			./unit_tests

.PHONY:		all debug clean flcean re tests_run test
