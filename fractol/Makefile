# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 11:34:08 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/17 12:45:54 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADERS = include/fractol.h

CC = cc

FLAGS = -Wall -Wextra -Werror -Ofast -march=native -mtune=native -funroll-loops

SRCPATH = src

SRCFILE = main.c parsing_param.c rendering.c calculation.c hook.c utils.c color.c key.c

SRC = $(addprefix $(SRCPATH)/, $(SRCFILE))

OBJPATH = obj

OBJFILE = $(SRCFILE:.c=.o)

OBJ = $(addprefix $(OBJPATH)/, $(OBJFILE))

LIBXPATH = minilibx-linux

LIBX = $(addprefix $(LIBXPATH)/, libmlx_Linux.a)

LIBFTPATH = libft

LIBFT = $(addprefix $(LIBFTPATH)/, libft.a)

all: $(OBJPATH) $(LIBX) $(LIBFT) $(NAME)

$(NAME): $(LIBX) $(LIBFTPATH) $(OBJ) $(HEADERS)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFTPATH) -I$(LIBFTPATH)/include -lft -L$(LIBXPATH) -lmlx -L/usr/lib -lXext -lX11

$(LIBX):
	$(MAKE) -C $(LIBXPATH)

$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)

$(OBJPATH):
	mkdir $(OBJPATH)

$(OBJPATH)/%.o : $(SRCPATH)/%.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJPATH)
	$(MAKE) -C $(LIBXPATH) clean
	$(MAKE) -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

.PHONY: all clean fclean test