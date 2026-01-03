# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/03 11:46:59 by dgibrat           #+#    #+#              #
#    Updated: 2026/01/03 16:30:30 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cd

HEADERS = include/test_minishell.h

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCPATH = src

SRCFILE = cmd_cd.c env.c

SRC = $(addprefix $(SRCPATH)/, $(SRCFILE))

OBJPATH = obj

OBJFILE = $(SRCFILE:.c=.o)

OBJ = $(addprefix $(OBJPATH)/, $(OBJFILE))

LIBFTPATH = libft

LIBFT = $(addprefix $(LIBFTPATH)/, libft.a)

all: $(OBJPATH) $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADERS)
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

.PHONY: all clean fclean