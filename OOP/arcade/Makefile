##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CXX						=				g++

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME					=				arcade

NAME_SDL				=				arcade_sdl2.so

NAME_NCURSES			=				arcade_ncurses.so

NAME_SFML				=				arcade_sfml.so

NAME_SNAKE				=				arcade_snake.so

NAME_NIBBLER			=				arcade_nibbler.so

NAME_TEST				=				unit_test

NAME_FUNC_TEST			=				## a shell file

## ===========================================================
## ===========================[SRC]===========================
## ===========================================================

SRC_CORE				=				core/core.cpp							\
										core/chargeLib.cpp						\
										core/closeLib.cpp						\
										core/findLib.cpp						\
										core/initLib.cpp						\
										core/menu.cpp							\

SRC_GRAPHICALS_SFML		=				Ldisplay/sfml/ADisplaySfml.cpp			\

SRC_GRAPHICALS_NCURSES	=				Ldisplay/ncurses/ADisplayNcurses.cpp	\

SRC_GRAPHICALS_SDL		= 				Ldisplay/sdl/ADisplaySdl.cpp			\

SRC_SNAKE				=				Lgame/snake/snake.cpp					\

SRC_NIBBLER				=				Lgame/nibbler/nibbler.cpp				\

BUILDDIR 				= 				build

OBJ_SRC 				= 				$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC_CORE))

OBJ_GAMES_SNAKE			= 				$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC_SNAKE))

OBJ_GAMES_NIBBLER 		= 				$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC_NIBBLER))

OBJ_GRAPHICALS_SFML		= 				$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC_GRAPHICALS_SFML))

OBJ_GRAPHICALS_NCURSES 	= 				$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC_GRAPHICALS_NCURSES))

OBJ_GRAPHICALS_SDL 		= 				$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC_GRAPHICALS_SDL))

$(BUILDDIR)/%.o: 	src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) -c -o $@ $<

TEST_SRC		=	##	tests/unit_tests/						\

## ===========================================================
## =========================[OPTIONS]=========================
## ===========================================================

CPPFLAGS				=				-fPIC

SFML_FLAGS				=				-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -fno-gnu-unique

NCURSE_FLAGS			=				-lncurses -fno-gnu-unique

SDL_FLAGS				=				-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2main -lSDL2 -fno-gnu-unique

FLAGS_GAMES				= 				-lm

RM						=				rm -f

CXXFLAGS				=				-std=c++20 									\
 										-Wall 										\
 										-Wextra										\
										-ldl										\
										$(CPPFLAGS)

TESTFLAGS				=				-lcriterion --coverage

COMPIL					=				$(CXX)  -shared -o

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

## ==========================[CORE]===========================

all: core games graphicals

core:	$(NAME)

$(NAME):	$(OBJ_SRC)
	$(CXX) -o $(NAME) $(OBJ_SRC) $(CXXFLAGS)

debug: re
debug: CXXFLAGS += -g3

## ==========================[GAMES]==========================


games: $(NAME_SNAKE) $(NAME_NIBBLER)

## ===[SNAKE]===

$(NAME_SNAKE): $(OBJ_GAMES_SNAKE)
	$(COMPIL) $(NAME_SNAKE) $(OBJ_GAMES_SNAKE) $(CXXFLAGS) $(FLAGS_GAMES)
	@mv $(NAME_SNAKE) lib/

## ===[NIBBLER]===

$(NAME_NIBBLER): $(OBJ_GAMES_NIBBLER)
	$(COMPIL) $(NAME_NIBBLER) $(OBJ_GAMES_NIBBLER) $(CXXFLAGS) $(FLAGS_GAMES)
	@mv $(NAME_NIBBLER) lib/

## =======================[GRAPHICALS]=======================

graphicals: $(NAME_SFML) $(NAME_NCURSES) $(NAME_SDL)

## ===[SDL]===

$(NAME_SDL): $(OBJ_GRAPHICALS_SDL)
	$(COMPIL) $(NAME_SDL) $(OBJ_GRAPHICALS_SDL) $(SDL_FLAGS) $(CXXFLAGS)
	@mv $(NAME_SDL) lib/

## ===[NCURSES]===

$(NAME_NCURSES): $(OBJ_GRAPHICALS_NCURSES)
	$(COMPIL) $(NAME_NCURSES) $(OBJ_GRAPHICALS_NCURSES) $(NCURSE_FLAGS) $(CXXFLAGS)
	@mv $(NAME_NCURSES) lib/

## ===[SFML]===

$(NAME_SFML): $(OBJ_GRAPHICALS_SFML)
	$(COMPIL) $(NAME_SFML) $(OBJ_GRAPHICALS_SFML) $(SFML_FLAGS) $(CXXFLAGS)
	@mv $(NAME_SFML) lib/


## =======================[DOCS]=============================

docs:
	doxygen Doxyfile
	cd docs/latex && make pdf && make && mv refman.pdf ../../
	mv refman.pdf doc.pdf
	mv doc.pdf ./doc
	firefox docs/html/index.html

## ===========================================================
## =======================[CLEAN]=============================
## ===========================================================

clean:
	$(RM) $(OBJ_SRC)
	$(RM) *.gcno *.gcda vgcore*

fclean: clean
	$(RM) $(NAME) $(NAME_TEST)
	$(RM) $(NAME_SNAKE) $(NAME_NIBBLER) $(NAME_SDL) $(NAME_NCURSES) $(NAME_SFML)
	@cd lib && $(RM) $(NAME_SNAKE) $(NAME_NIBBLER) $(NAME_SDL) $(NAME_NCURSES) $(NAME_SFML)
	if test -d docs; then \
        rm -r docs; \
    fi

fclean_tests:
	$(RM) unit_tests
	$(RM) *gcda
	$(RM) *gcno

re: fclean all clean

## ===========================================================
## =======================[TESTS]=============================
## ===========================================================

unit_tests:    $(NAME) fclean
	gcc -o unit_tests tests/tests.c $(CXXFLAGS)  -lm --coverage -lcriterion

tests_run:	fclean $(OBJ_SRC)
			$(CXX) -o $(NAME_TEST) $(OBJ_SRC) $(TEST_SRC) $(TESTFLAGS) $(CXXFLAGS)
			./$(NAME_TEST)
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

## ===========================================================
## ===========================[PHONY]=========================
## ===========================================================

.PHONY: all debug clean fclean tests_run unit_tests fclean_tests
