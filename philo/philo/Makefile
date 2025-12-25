# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 15:14:22 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/25 15:44:30 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADERS = include/philo.h

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCPATH = src

SRCFILE = main.c utils.c

SRC = $(addprefix $(SRCPATH)/, $(SRCFILE))

OBJPATH = obj

OBJFILE = $(SRCFILE:.c=.o)

OBJ = $(addprefix $(OBJPATH)/, $(OBJFILE))

all: $(OBJPATH) $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADERS)
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

.PHONY: all clean fclean test