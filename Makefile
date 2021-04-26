##
## EPITECH PROJECT, 2021
## makefile
## File description:
## project makefile
##

SRC	=	src/main.c									\
		src/usage.c									\
		src/binary/binary_launcher.c				\
		src/constant/instruction_handlers.c			\
		src/constant/signal_names.c					\
		src/constant/syscall.c						\
		src/constant/syscall_special.c				\
		src/constant/errno.c						\
		src/stack/sstack.c							\
		src/tracer/system/get_registers.c			\
		src/tracer/system/opcode_match.c			\
		src/tracer/system/step_forward.c			\
		src/tracer/process_instruction.c			\
		src/tracer/trace_binary.c					\
		src/tracer/modules/trace_signal.c			\
		src/tracer/modules/errno_manager.c			\
		src/tracer/tracer_destroy.c					\
		src/tracer/tracer_init.c					\
		src/tracer/handler/ret_instruction_handler.c\
		src/tracer/handler/syscall/display/print_int.c		\
		src/tracer/handler/syscall/display/print_long.c		\
		src/tracer/handler/syscall/display/print_pointer.c	\
		src/tracer/handler/syscall/display/print_register.c	\
		src/tracer/handler/syscall/display/print_size_t.c	\
		src/tracer/handler/syscall/display/print_string.c	\
		src/tracer/handler/syscall/display/print_substring.c\
		src/tracer/handler/syscall/tracer/section/syscall_show_args.c	\
		src/tracer/handler/syscall/tracer/section/syscall_show_name.c	\
		src/tracer/handler/syscall/tracer/section/syscall_show_return.c	\
		src/tracer/handler/syscall/tracer/special_case/spe_stat.c		\
		src/tracer/handler/syscall/tracer/special_case/special_case_manager.c	\
		src/tracer/handler/syscall/tracer/special_case/spec_handler_read.c		\
		src/tracer/handler/syscall/tracer/utility/get_syscall_info.c			\
		src/tracer/handler/syscall/tracer/utility/register_find.c				\
		src/tracer/handler/syscall/tracer/syscall_instruction_handler.c			\
		src/proc_maps/proc_maps_line.c									\
		src/proc_maps/proc_maps_parser.c								\
		src/proc_maps/proc_maps_match.c									\
		src/utility/my_str_to_word_array.c								\

OBJ	=	$(SRC:.c=.o)

NAME	=	ftrace

INCLUDES	=	-I include -I include/syscall -I include/maps
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