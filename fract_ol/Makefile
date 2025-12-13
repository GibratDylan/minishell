# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 11:34:08 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/13 20:51:57 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

CC = cc

FLAGS = -Wall -Wextra -Werror -O3 -march=native -ffast-math

SRCPATH = src

SRCFILE = main.c parsing_param.c rendering.c calculation.c hook.c utils.c

SRC = $(addprefix $(SRCPATH)/, $(SRCFILE))

OBJPATH = obj

OBJFILE = $(SRCFILE:.c=.o)

OBJ = $(addprefix $(OBJPATH)/, $(OBJFILE))

LIBXPATH = minilibx-linux

LIBX = $(addprefix $(LIBXPATH)/, libmlx_Linux.a)

LIBFTPATH = libft

LIBFT = $(addprefix $(LIBFTPATH)/, libft.a)

all: $(LIBX) $(LIBFT) $(NAME)

$(NAME): $(LIBX) $(LIBFTPATH) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFTPATH) -I$(LIBFTPATH)/include -lft -L$(LIBXPATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

$(LIBX):
	$(MAKE) -C $(LIBXPATH)

$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)

$(OBJPATH)/%.o : $(SRCPATH)/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBXPATH) clean
	$(MAKE) -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

.PHONY: all clean fclean test