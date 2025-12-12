# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 11:34:08 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/12 15:51:27 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

CC = cc

FLAGS = -Wall -Wextra -Werror -O3

SRCPATH = src

SRCFILE = main.c

SRC = $(addsuffix $(SRCFILE), $(SRCPATH)/)

OBJPATH = obj

OBJFILE = $(SRCFILE:.c=.o)

OBJ = $(addsuffix $(OBJFILE), $(OBJPATH)/)

LIBXPATH = minilibx-linux

LIBX = $(addsuffix libmlx_Linux.a, $(LIBXPATH)/)

all: $(LIBX) $(NAME)

$(NAME): $(LIBX) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBXPATH) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(LIBX):
	$(MAKE) -C $(LIBXPATH)

$(OBJPATH)/%.o : $(SRCPATH)/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBXPATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBXPATH) fclean

re: fclean all

.PHONY: all clean fclean bonus test