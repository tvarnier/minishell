# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/15 23:02:25 by tvarnier     #+#   ##    ##    #+#        #
#    Updated: 2019/04/03 14:26:17 by tvarnier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a

HEADER = ./includes/minishell.h

SRC =	main.c \
		command_launch.c \
		command_builtins.c \
		builtins/b_cd.c \
		builtins/b_echo.c \
		builtins/b_env.c \
		builtins/b_exit.c \
		builtins/b_setenv.c \
		builtins/b_unsetenv.c \
		command_system.c \
		args_split.c \
		args_alloc.c \
		print.c \
		error.c \
		struct_shell.c \
		env.c \
		env_set.c \
		read/get_command.c \
		read/modif_command.c

SRC_DIR = srcs
SRC_CAT = builtins read
SRCS = $(SRC:%.c=$(SRC_DIR)/%.c)

OBJ_DIR = obj
OBJ_CAT = $(SRC_CAT:%=$(OBJ_DIR)/%)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ_CAT) $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIB) $(FLAGS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_CAT):
	mkdir $@

$(LIB):
	make -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) -I includes -o $@ -c $< $(FLAGS)

clean:
	make -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LIB)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean re
