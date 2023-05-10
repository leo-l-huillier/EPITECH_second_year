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

NAME			=		nanotekspice

NAME_TEST		=		tests_run

NAME_FUNC_TEST	=		## a shell file

NAME_LIB		=		libmy.a

# ## ===========================================================
# ## ===========================[SRC]===========================
# ## ===========================================================

MAIN 	= 		main.cpp 										\

SRC		=		parsing/checkfile.cpp							\
#				command/Command.cpp								\
				component/abstract/AComponent.cpp				\
				component/Advanced/A1081.cpp					\
				component/Advanced/A2716.cpp					\
				component/Advanced/A4008.cpp					\
				component/Advanced/A4013.cpp					\
				component/Advanced/A4017.cpp					\
				component/Advanced/A4040.cpp					\
				component/Advanced/A4094.cpp					\
				component/Advanced/A4512.cpp					\
				component/Advanced/A4514.cpp					\
				component/Advanced/A4801.cpp					\
				component/elementaryComponent/and.cpp			\
				component/elementaryComponent/not.cpp			\
				component/elementaryComponent/or.cpp			\
				component/elementaryComponent/xor.cpp			\
				component/gatesComponent/andGate.cpp			\
				component/specialComponent/clock.cpp			\
				component/specialComponent/input.cpp			\
				component/specialComponent/output.cpp			\
				component/specialComponent/true.cpp				\
				component/specialComponent/false.cpp			\
				componentApplication/compute/compute.cpp		\
				componentApplication/componentApplication.cpp	\

BUILDDIR = build

OBJ_SRC = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(MAIN) $(SRC))

$(BUILDDIR)/%.o: 	src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

TEST_SRC		=		tests/unit_tests/testParcing.cpp		\

OBJ_LIB			=	$(LIB:.cpp=.o)

CPPFLAGS_HEADERS =	src/utils			\

## ===========================================================
## =========================[OPTIONS]=========================
## ===========================================================

RM				=	rm -f

CFLAGS			=

CXXFLAGS		=	-std=c++20 -Wall -Wextra $(addprefix -I./, $(CPPFLAGS_HEADERS))

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
			$(CXX) -o $(NAME_TEST) src/parsing/checkfile.cpp tests/unit_tests/testParcing.cpp -lcriterion --coverage
			./tests_run
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
