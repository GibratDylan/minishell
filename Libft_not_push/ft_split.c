/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:42:43 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/08 12:02:37 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_array(char const *s, char c)
{
	unsigned long	i;
	size_t			len_array;

	i = 0;
	len_array = 0;
	while (s[i] != '\0' && i < ULONG_MAX)
	{
		if ((s[i] == c && s[i + 1] != c) || (s[i] == c && s[i + 1] != '\0'))
			len_array++;
		i++;
	}
	return (len_array);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;
	char			**array;

	i = 0;
	j = 0;
	start = 0;
	if (s == NULL)
		return (NULL);
	array = calloc(ft_len_array(s, c) + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			start = i + 1;
		if ((s[i + 1] == c && s[i] != c) || (s[i + 1] == '\0' && s[i] != c))
			array[j++] = ft_substr(s, start, i - start + 1);
		i++;
	}
	return (array);
}
