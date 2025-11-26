/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:20:15 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/08 15:56:54 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	i;
	char			c_c;
	size_t			len_s;

	c_c = (char)c;
	len_s = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (c_c == '\0')
		return ((char *)&s[len_s]);
	i = 0;
	while (i <= len_s)
	{
		if (c_c == s[len_s - i])
			return ((char *)&s[len_s - i]);
		i++;
	}
	return (NULL);
}
