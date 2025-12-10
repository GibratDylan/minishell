/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:58:55 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 18:58:02 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned long	i;
	size_t			len_s;
	char			*result;

	len_s = ft_strlen(s);
	if (s == NULL || f == NULL || len_s + 1 > ULONG_MAX / sizeof(char))
		return (NULL);
	result = ft_malloc(len_s + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[len_s] = '\0';
	return (result);
}
