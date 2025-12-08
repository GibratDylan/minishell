# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 11:36:20 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/08 18:57:13 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = main.c rules_a.c rules_b.c init.c recursive_chunk.c sort.c turkish.c utils.c

OBJ = $(SRC:.c=.o)

LIBFTPATH = libft

LIBFT = $(LIBFTPATH)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFTPATH) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

test: $(OBJ) $(LIBFT)
	gcc -g -O0 $(OBJ) -o $(NAME) -L$(LIBFTPATH) -lft -no-pie
	valgrind -q --leak-check=full --show-reachable=yes --track-origins=yes --tool=memcheck ./$(NAME) 1