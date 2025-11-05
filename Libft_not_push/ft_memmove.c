/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:13:51 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/05 10:35:14 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	unsigned char	*uc_dest;
	unsigned char	*uc_src;

	uc_dest = (unsigned char *) dest;
	uc_src = (unsigned char *) src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			uc_dest[i] = uc_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			uc_dest[i - 1] = uc_src[i - 1];
			i--;
		}
	}
	return (dest);
}
