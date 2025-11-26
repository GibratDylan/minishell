# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 16:53:19 by dgibrat           #+#    #+#              #
#    Updated: 2025/11/26 10:28:17 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_itoa_base.c ft_strdup_null.c

OBJ = $(SRC:.c=.o)

LIBFTPATH = libft/

SRCLIBFT = ft_strlcpy.c ft_putchar_fd.c ft_strchr.c ft_strdup.c\
ft_strlen.c ft_putstr_fd.c ft_itoa.c

OBJLIBFT = $(SRCLIBFT:.c=.o)

all: $(OBJLIBFT) $(NAME)

$(NAME): $(OBJ) $(OBJLIBFT)
	ar rcs $(NAME) $(OBJ) $(addprefix $(LIBFTPATH),$(OBJLIBFT))

$(OBJLIBFT):
	$(MAKE) -C libft $@

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all fclean clean re test