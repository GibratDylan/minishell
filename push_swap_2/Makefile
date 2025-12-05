# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 11:36:20 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/04 14:09:59 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = main.c rules.c

OBJ = $(SRC:.c=.o)

LIBFTPATH = libft

LIBFT = libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(NAME) $(OBJ) $(LIBFTPATH)/$(LIBFT)

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
	valgrind -q --leak-check=full --show-reachable=yes --track-origins=yes --tool=memcheck ./$(NAME) 65 71 58 18 26 32 62 49 21 52 89 16 30 92 43 54 84 87 90 34 77 1 51 4 40 8 27 56 91 46 6 100 69 29 23 35 13 88 98 95 20 96 31 70 66 28 94 7 15 59 22 93 99 53 85 64 3 55 45 36 72 41 19 44 61 12 37 50 68 24 63 14 10 73 33 48 2 17 80 86 81 83 75 25 76 67 60 79 5 78 82 47 57 38 11 42 97 39 74 9
.PHONY: all fclean clean re test