# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 16:57:37 by dgibrat           #+#    #+#              #
#    Updated: 2025/12/06 19:03:11 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SCRS = ft_memset.c ft_strlen.c ft_strncmp.c ft_atoi.c ft_itoa.c ft_putchar_fd.c\
ft_putstr_fd.c ft_printf.c ft_itoa_base.c ft_strdup_null.c ft_strlcpy.c ft_strchr.c\
ft_strdup.c ft_memcpy.c ft_bzero.c ft_calloc.c ft_strjoin.c ft_strnstr.c ft_substr.c

OBJS = $(SCRS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus fclean clean re