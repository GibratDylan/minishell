# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/03 11:46:59 by dgibrat           #+#    #+#              #
#    Updated: 2026/01/05 14:25:08 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_minishell

HEADERS = include/test_minishell.h

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCPATH = src

SRCFILE = env.c main.c pid_handler.c exec_all_cmd.c exec_cmd.c

SRC = $(addprefix $(SRCPATH)/, $(SRCFILE))

OBJPATH = obj

OBJFILE = $(SRCFILE:.c=.o)

OBJ = $(addprefix $(OBJPATH)/, $(OBJFILE))

LIBFTPATH = libft

LIBFT = $(addprefix $(LIBFTPATH)/, libft.a)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJPATH) $(LIBFT) $(OBJ) $(HEADERS)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFTPATH) -I$(LIBFTPATH)/include -lft -lreadline

$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)

$(OBJPATH):
	mkdir $(OBJPATH)

$(OBJPATH)/%.o : $(SRCPATH)/%.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJPATH)
	$(MAKE) -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

debug: FLAGS += -g
debug: fclean $(NAME)

test: debug
	valgrind ./$(NAME) ls -la

run: re
	./$(NAME)
	
.PHONY: all clean fclean test run debug