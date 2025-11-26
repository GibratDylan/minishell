# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 11:36:20 by dgibrat           #+#    #+#              #
#    Updated: 2025/11/26 17:08:19 by dgibrat          ###   ########.fr        #
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
	valgrind -q --leak-check=full --show-reachable=yes --track-origins=yes --tool=memcheck ./$(NAME) -7560 2748 116 8006 -6470 5787 -9210 -1259 -4875 223 1348 -5413 -8865 2393 303 5559 -3883 3940 6597 7766 -267 -2112 -3001 2046 -4560 7645 -8755 8640 -4246 -4944 2345 -8574 -3473 2948 2263 7273 7339 7834 -9328 6893 -3790 -6932 -1023 6621 -9975 -4616 -7113 -3119 8634 9340 8101 -7754 -8456 9363 -7792 2874 -6091 -8577 -8520 -9318 -5448 -310 -6139 -441 8040 -3415 -2565 -8080 7048 6373 -8787 3578 -9950 7003 1495 -2183 9853 6836 1605 5277 7763 -8836 3147 3434 8529 600 -8763 7507 5604 -3274 -3934 -624 -6440 -3887 9815 1463 6356 -7629 1709 7970

.PHONY: all fclean clean re test