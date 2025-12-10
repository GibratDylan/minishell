# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 11:36:20 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/10 11:49:00 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = main.c rules_a.c rules_b.c init.c recursive_chunk.c sort.c turkish.c utils.c turkish_2.c recursive_chunk_2.c

SRC_BONUS = main_bonus.c init_bonus.c rules_a_bonus.c rules_b_bonus.c rules_bonus.c utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS =  $(SRC_BONUS:.c=.o)

LIBFTPATH = libft

LIBFT = $(addsuffix libft.a, $(LIBFTPATH)/)

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFTPATH) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

bonus: $(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) -L$(LIBFTPATH) -lft

test: $(OBJ) $(LIBFT)
	gcc -g -O0 $(OBJ) -o $(NAME) -L$(LIBFTPATH) -lft -no-pie
	valgrind -q --leak-check=full --show-reachable=yes --track-origins=yes --tool=memcheck ./$(NAME) 72 32 13 3 54 56 12 89 38 29 90 85 81 86 64 35 76 10 20 75 14 84 48 83 7 9 60 97 25 36 37 40 41 28 23 68 22 78 17 98 0 44 43 19 24 58 80 5 50 16 71 62 93 30 39 73 67 45 79 1 42 47 61 95 27 53 70 4 51 52 65 2 49 63 77 57 99 33 82 94 96 11 88 46 87 92 59 18 34 26 15 74 8 31 91 55 21 66 69 6

test_bonus: $(OBJ_BONUS) $(LIBFT)
	gcc -g -O0 $(OBJ_BONUS) -o $(NAME_BONUS) -L$(LIBFTPATH) -lft -no-pie
	valgrind -q --leak-check=full --show-reachable=yes --track-origins=yes --tool=memcheck ./$(NAME_BONUS) 72 32 13 3 54 56 12 89 38 29 90 85 81 86 64 35 76 10 20 75 14 84 48 83 7 9 60 97 25 36 37 40 41 28 23 68 22 78 17 98 0 44 43 19 24 58 80 5 50 16 71 62 93 30 39 73 67 45 79 1 42 47 61 95 27 53 70 4 51 52 65 2 49 63 77 57 99 33 82 94 96 11 88 46 87 92 59 18 34 26 15 74 8 31 91 55 21 66 69 6

.PHONY: all clean fclean bonus test