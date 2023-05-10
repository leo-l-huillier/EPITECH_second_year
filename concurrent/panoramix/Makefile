##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC				=	gcc

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME			=		panoramix

NAME_TEST		=		unit_test

NAME_FUNC_TEST	=		## a shell file

NAME_LIB		=		libmy.a

# ## ===========================================================
# ## ===========================[SRC]===========================
# ## ===========================================================

MAIN 	= 		main.c 					\

SRC		=		druid.c					\
				villager.c 				\
				end.c 					\
				struct.c 				\
				panoramix.c				\
				test.c					\

BUILDDIR = build

OBJ_MAIN = $(patsubst %.c, $(BUILDDIR)/%.o, $(MAIN))

OBJ_SRC = $(patsubst %.c, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o: 	src/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

TEST_SRC		=		tests/unit_tests/test_druid.c	\

OBJ_LIB			=	$(LIB:.c=.o)

CPPFLAGS_HEADERS =	include/			\

## ===========================================================
## =========================[OPTIONS]=========================
## ===========================================================

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -lpthread

CXXFLAGS		=

LDFLAGS			=	-L./ -lmy

TESTFLAGS		=	-lcriterion --coverage

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

all:	$(NAME)

## @ar rc $(NAME_LIB) $(OBJ_LIB)
## $(LDFLAGS)

$(NAME):	$(OBJ_MAIN) $(OBJ_SRC) $(OBJ_LIB)
	$(CXX) -o $(NAME) $(OBJ_MAIN) $(OBJ_SRC) $(CFLAGS)

debug: CPPFLAGS += -g3
debug: re

clean:
	@$(RM) $(OBJ_LIB) $(OBJ_SRC)
	@$(RM) *.gcno *.gcda vgcore*

fclean: clean
	@$(RM) $(NAME) $(NAME_TEST) $(NAME_LIB) $(NAME_TEST)

fclean_tests:
	$(RM) unit_tests
	$(RM) *gcda
	$(RM) *gcno
	$(RM) tester

re: fclean all clean

unit_tests:    $(NAME) fclean
	gcc -o unit_tests tests/tests.c $(CXXFLAGS)  -lm --coverage -lcriterion

tests_run:	fclean $(OBJ_LIB) $(OBJ_SRC)
			$(CXX) -o $(NAME_TEST) src/druid.c $(TEST_SRC) $(TESTFLAGS)
			./$(NAME_TEST)
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

# tests:		re clean
# 			@mv tests/$(NAME_FUNC_TEST) ./
# 			./$(NAME_FUNC_TEST)
# 			@mv ./$(NAME_FUNC_TEST) ./tests

## ===========================================================
## ===========================[PHONY]=========================
## ===========================================================

.PHONY: fclean all clean debug tests_run test_run unit_tests fclean_tests
