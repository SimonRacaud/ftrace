##
## EPITECH PROJECT, 2021
## makefile
## File description:
## project makefile
##

SRC	=	src/main.c									\
		src/constante.c								\
		src/ftrace_source_const.c					\
		src/elf/maps_proc.c							\
		src/tools/tab_manage.c						\
		src/tools/str_to_array.c					\
		src/display/display_help.c					\
		src/init_struct/init_struct.c				\
		src/process_manage/call_function.c			\
		src/process_manage/process_manage.c			\
		src/process_manage/func/exit_func.c			\
		src/process_manage/func/call_syscall.c		\
		src/process_manage/func/call_enter_func.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	ftrace

INCLUDES	=	-I include
CFLAGS		=	$(INCLUDES) -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(ECHO)
		@gcc -o $(NAME) $(OBJ) -lelf\
		&& $(ECHO) $(BOLD) $(GREEN)"► BUILD SUCCESS !"$(DEFAULT) || $(ECHO) $(BOLD) $(RED)"► BUILD FAILED"$(DEFAULT)

clean:
		@rm -f $(OBJ)
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" CLEAN "$(DEFAULT))

fclean: clean
		@rm -f $(NAME)
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" FCLEAN "$(DEFAULT))

debug: CFLAGS += -g
debug: re

re:	fclean all


%.o :		%.c
		@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev

tests_local:
		gcc -Wall -Wextra -o0 -pipe -o test tests/test.c

.PHONY: all clean fclean re debug


ECHO    =       /bin/echo -e
DEFAULT =       "\033[00m"

DEFAULT =       "\e[0m"
BOLD    =       "\e[1m"
DIM     =       "\e[2m"
UNDLN   =       "\e[4m"
SHINE   =       "\e[5;37m"
RODE    =       "\e[9;37m"

BLACK   =       "\e[30m"
RED     =       "\e[31m"
GREEN   =       "\e[32m"
YELLOW  =       "\e[33m"
BLUE    =       "\e[34m"
MAGEN   =       "\e[35m"
CYAN    =       "\e[36m"
WHITE   =       "\e[1;37m"

LIGHT_RED       =       "\e[91m"
LIGHT_GREEN     =       "\e[92m"
LIGHT_YELLOW    =       "\e[93m"
LIGHT_BLUE      =       "\e[94m"
LIGHT_MAGEN     =       "\e[95m"
LIGHT_CYAN      =       "\e[96m"