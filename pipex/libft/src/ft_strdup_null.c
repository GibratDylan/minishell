/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:03:04 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 08:34:37 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup_null(const char *s)
{
	unsigned long	i;
	char			*dest;
	size_t			len_src;

	len_src = ft_strlen(s);
	if (s == NULL || len_src + 1 > ULONG_MAX / sizeof(char))
		return (ft_strdup("(null)"));
	dest = ft_malloc(len_src + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
