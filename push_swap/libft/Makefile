# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 16:57:37 by dgibrat           #+#    #+#              #
#    Updated: 2025/11/26 15:25:24 by dgibrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SCRS = ft_memset.c ft_strlen.c ft_strncmp.c ft_atoi.c ft_itoa.c ft_putchar_fd.c\
ft_putstr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstdelone.c ft_lstclear.c ft_printf.c\
ft_itoa_base.c ft_strdup_null.c ft_strlcpy.c ft_strchr.c ft_strdup.c ft_lstsize.c

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