/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:36:52 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/07 15:13:03 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*uc_s;
	unsigned char	uc_c;

	i = 0;
	uc_c = (unsigned char)c;
	uc_s = (unsigned char *)s;
	while (i < n)
	{
		if (uc_c == uc_s[i])
			return ((char *)&uc_s[i]);
		i++;
	}
	return (NULL);
}
