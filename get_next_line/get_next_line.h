/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:05:31 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/20 14:46:26 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int len, int c);
void	ft_strlcpy(char *dst, const char *src, size_t siz);
char	*ft_strjoin(char const *s1, char const *s2, unsigned int len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif