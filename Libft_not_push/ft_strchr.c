/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:46:26 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/08 15:54:28 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;
	char			c_c;

	c_c = (char)c;
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (c_c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (c_c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
