# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 15:14:22 by dgibrat           #+#    #+#              #
#    Updated: 2026/01/01 18:53:54 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

HEADERS = include/philo_bonus.h

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCPATH = src

SRCFILE = main.c ft_memset.c ft_malloc.c ft_malloc_utils.c action_think.c\
ft_lstadd_back.c ft_calloc.c ft_bzero.c ft_lstlast.c clock.c\
init_philo.c init_all.c take_fork.c\
ft_atoi.c philosopher.c action_fork.c action_eat.c\
action_sleep.c ft_itoa.c ft_strncmp.c ft_strlen.c init_attr.c close_all_philos.c\
wait_process_end.c stop.c

SRC = $(addprefix $(SRCPATH)/, $(SRCFILE))

OBJPATH = obj

OBJFILE = $(SRCFILE:.c=.o)

OBJ = $(addprefix $(OBJPATH)/, $(OBJFILE))

all: $(OBJPATH) $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJPATH):
	mkdir $(OBJPATH)

$(OBJPATH)/%.o : $(SRCPATH)/%.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean