# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 11:36:20 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/09 16:57:43 by dgibrat          ###   ########.fr        #
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

all: libft $(NAME)

$(NAME): $(OBJ) libft
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFTPATH) -lft

libft:
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

bonus: libft $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) libft
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) -L$(LIBFTPATH) -lft

test: $(OBJ) libft
	gcc -g -O0 $(OBJ) -o $(NAME) -L$(LIBFTPATH) -lft -no-pie
	valgrind -q --leak-check=full --show-reachable=yes --track-origins=yes --tool=memcheck ./$(NAME) 1

.PHONY: all libft clean fclean bonus test