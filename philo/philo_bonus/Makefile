# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 15:14:22 by dgibrat           #+#    #+#              #
#    Updated: 2026/01/02 19:22:23 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

HEADERS = include/philo_bonus.h

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCPATH = src

SRCFILE = main_bonus.c ft_memset_bonus.c ft_malloc_bonus.c\
ft_lstadd_back_bonus.c ft_calloc_bonus.c ft_bzero_bonus.c ft_lstlast_bonus.c\
clock_bonus.c init_philo_bonus.c init_all_bonus.c take_fork_bonus.c\
ft_atoi_bonus.c philosopher_bonus.c action_fork_bonus.c action_eat_bonus.c\
action_sleep_bonus.c ft_itoa_bonus.c ft_strncmp_bonus.c ft_strlen_bonus.c\
init_attr_bonus.c close_all_philos_bonus.c wait_process_end_bonus.c\
stop_bonus.c action_think_bonus.c ft_malloc_utils_bonus.c\

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