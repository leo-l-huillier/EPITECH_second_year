##
## EPITECH PROJECT, 2023
## wolfram
## File description:
## Makefile
##

BINARY_PATH 	:=	$(shell stack path --local-install-root)

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME			=		wolfram

NAME_TEST		=		nanotekspice_tests

NAME_FUNC_TEST	=		## a shell file

NAME_LIB		=		libmy.a

# ## ===========================================================
# ## ===========================[SRC]===========================
# ## ===========================================================

MAIN 	= 		src/main.hs

SRC		=

BUILDDIR = build

OBJ_SRC = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(MAIN) $(SRC))

$(BUILDDIR)/%.o: 	src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

TEST_SRC		=	##	tests/unit_tests/	\

OBJ_LIB			=	$(LIB:.cpp=.o)

CPPFLAGS_HEADERS =	src/utils			\

## ===========================================================
## =========================[OPTIONS]=========================
## ===========================================================

RM				=	rm -f

CFLAGS			=

HCFLAGS			=	-Wall -Wextra $(addprefix -I./, $(CPPFLAGS_HEADERS))

LDFLAGS			=	-L./ -lmy

TESTFLAGS		=	-lcriterion --coverage


## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

all:
	stack build
	cp $(BINARY_PATH)/bin/$(NAME)-exe ./$(NAME)

## @ar rc $(NAME_LIB) $(OBJ_LIB)
## $(LDFLAGS)

$(NAME):	$(OBJ_SRC) $(OBJ_LIB)
	$(BINARY_PATH) -o $(NAME) $(OBJ_SRC) $(HCFLAGS)

debug: CPPFLAGS += -g3
debug: re

clean:
	stack clean

fclean: clean
		$(RM) $(NAME)
#	@$(RM) $(NAME) $(NAME_TEST) $(NAME_LIB) $(NAME_TEST)

fclean_tests:
	$(RM) unit_tests
	$(RM) *gcda
	$(RM) *gcno
	$(RM) tester

re: fclean all

unit_tests:    $(NAME) fclean
	gcc -o unit_tests tests/tests.c $(HCFLAGS)  -lm --coverage -lcriterion

tests_run:	fclean $(OBJ_LIB) $(OBJ_SRC)
			$(BINARY_PATH) -o $(NAME_TEST) $(OBJ_SRC) $(TEST_SRC) $(TESTFLAGS) $(HCFLAGS)
			./$(NAME_TEST)
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

## ===========================================================
## ===========================[PHONY]=========================
## ===========================================================

.PHONY: fclean all clean debug tests_run test_run unit_tests fclean_tests