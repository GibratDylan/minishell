/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:22:43 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/18 17:24:30 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0' && i < ULONG_MAX)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;
	char			c_c;

	c_c = (char)c;
	if (s == NULL)
		return (NULL);
	if (c_c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i] != '\0')
	{
		if (c_c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	unsigned long	i;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	while ((src != NULL) && (src[i] != '\0') && i + 1 < siz)
	{
		dst[i] = src[i];
		i++;
	}
	if (siz != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*subs;

	len_s = ft_strlen(s);
	if (len > len_s - start)
		len = len_s - start;
	subs = malloc(sizeof(char) * (len + 1));
	if (subs == NULL)
		return (NULL);
	ft_strlcpy(subs, &s[start], len + 1);
	return (subs);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s2 == NULL || len_s1 + len_s2 + 1 > ULONG_MAX / sizeof(char))
		return (NULL);
	result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (result == NULL)
		return (NULL);
	if ((len_s1 + len_s2 + 1) == 1)
	{
		free(result);
		result = NULL;
		return (result);
	}
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcpy(&result[len_s1], s2, len_s2 + 1);
	return (result);
}
