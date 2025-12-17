/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:58:17 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 08:34:28 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t			len_dst;
	size_t			len_src;
	unsigned long	i;

	if (dst == NULL || src == NULL)
		return (0);
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= siz)
		return (siz + len_src);
	i = 0;
	while (src[i] != '\0' && ((i + 1) < (siz - len_dst)))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (siz > 0)
	{
		dst[len_dst + i] = '\0';
	}
	return (len_dst + len_src);
}
