# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 15:14:22 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/17 11:35:23 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADERS = include/pipex.h

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCPATH = src

SRCFILE = main.c

SRC = $(addprefix $(SRCPATH)/, $(SRCFILE))

OBJPATH = obj

OBJFILE = $(SRCFILE:.c=.o)

OBJ = $(addprefix $(OBJPATH)/, $(OBJFILE))

LIBFTPATH = libft

LIBFT = $(addprefix $(LIBFTPATH)/, libft.a)

all: $(OBJPATH) $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADERS)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFTPATH) -I$(LIBFTPATH)/include -lft

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

.PHONY: all clean fclean test