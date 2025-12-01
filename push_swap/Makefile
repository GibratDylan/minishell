# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 11:36:20 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/01 10:56:44 by dgibrat          ###   ########.fr        #
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
	valgrind -q --leak-check=full --show-reachable=yes --track-origins=yes --tool=memcheck ./$(NAME) 5 55 44 91 96 61 30 63 72 70 83 9 25 42 57 69 26 88 36 59 82 94 51 6 84 4 49 58 48 76 23 27 81 62 79 86 10 17 12 52 75 67 13 77 41 90 50 53 8 32 14 16 98 80 40 99 89 46 97 68 71 95 19 54 29 1 65 21 43 37 74 24 3 39 73 93 18 60 87 15 85 47 78 22 100 33 34 35 11 64 56 20 2 31 38 45 66 7 28 92

.PHONY: all fclean clean re test