##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CXX				=	g++

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME			=		206neutrinos

NAME_TEST		=		206neutrinos_tests

NAME_FUNC_TEST	=		## a shell file

NAME_LIB		=		libmy.a

# ## ===========================================================
# ## ===========================[SRC]===========================
# ## ===========================================================

MAIN 	= 		main.cpp

SRC		= 		

BUILDDIR = build

OBJ_SRC = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(MAIN) $(SRC))

$(BUILDDIR)/%.o: 	src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

TEST_SRC		=		tests/unit_tests/test.cpp	\

OBJ_LIB			=	$(LIB:.cpp=.o)

CPPFLAGS_HEADERS =	src/utils			\

## ===========================================================
## =========================[OPTIONS]=========================
## ===========================================================

RM				=	rm -f

CFLAGS			=

CXXFLAGS		=	-std=c++17 -Wall -Wextra $(addprefix -I./, $(CPPFLAGS_HEADERS))

LDFLAGS			=	-L./ -lmy

TESTFLAGS		=	-lcriterion --coverage


## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

all:	$(NAME)

## @ar rc $(NAME_LIB) $(OBJ_LIB)
## $(LDFLAGS)

$(NAME):	$(OBJ_SRC) $(OBJ_LIB)
	$(CXX) -o $(NAME) $(OBJ_SRC) $(CXXFLAGS)

debug: CPPFLAGS += -g3
debug: re

clean:
	@$(RM) $(OBJ_LIB) $(OBJ_SRC)
	@$(RM) *.gcno *.gcda vgcore*

fclean: clean
	@$(RM) $(NAME) $(NAME_TEST) $(NAME_LIB) $(NAME_TEST) tester data

fclean_tests:
	$(RM) unit_tests
	$(RM) *gcda
	$(RM) *gcno
	$(RM) tester

re: fclean all clean

unit_tests:    $(NAME) fclean
	gcc -o unit_tests tests/tests.c $(CXXFLAGS)  -lm --coverage -lcriterion

tests: tests_run test_run

tests_run:	fclean $(OBJ_LIB) $(OBJ_SRC)
			$(CXX) -o $(NAME_TEST) src/205IQ.cpp $(TEST_SRC) $(TESTFLAGS) $(CXXFLAGS)
			./$(NAME_TEST)
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

test_run: 	re
	./tests/fonctional/tests.sh

# tests:		re clean
# 			@mv tests/$(NAME_FUNC_TEST) ./
# 			./$(NAME_FUNC_TEST)
# 			@mv ./$(NAME_FUNC_TEST) ./tests

## ===========================================================
## ===========================[PHONY]=========================
## ===========================================================

.PHONY: fclean all clean debug tests_run test_run unit_tests fclean_tests